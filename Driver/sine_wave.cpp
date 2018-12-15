#include "sine_wave.h"
#include "Tlc5940.h"

const double step_size = (2*PI / 16); //offset each led a bit for a wavy effect

Sinewave::Sinewave(const common::Config& configuration): configuration{configuration}
{}

void Sinewave::simulate()
{
  unsigned long actual_time = millis();
  unsigned long previous_time = millis();
  double duration = common::read_pot(configuration.speed_pot, 2000, 5000);
  double sine_step = 2*PI / duration;
  double sine_prev_state = 0.0;
  double sine_actual_state = 0.0;
  while(true)
  {
    actual_time = millis();
    unsigned long delta_time = actual_time - previous_time;
    sine_actual_state = sine_prev_state + sine_step*delta_time;
    wave(sine_actual_state);
    previous_time = actual_time;
    sine_prev_state = sine_actual_state;
  }
}

void Sinewave::color(int channel_start, int channel_end, double sine_state)
{
  for (int i = channel_start; i < channel_end; ++i)
  {
    double led = common::read_pot(configuration.bright_pot, configuration.min_brightness, configuration.max_brightness);
    int led_brightness = static_cast<int>((sin(sine_state + i*step_size)+1) * led);
    Tlc.set(i, led_brightness);
  }
}

void Sinewave::wave(double sine_state)
{
  for (int layer = 0; layer < configuration.layer_count; ++layer)
  {
    common::prime_layer(layer, configuration.layer_count, configuration.layer_pins);
    color(0, 16, sine_state);
    color(16, 32, sine_state + PI/3);
    color(32, 48, sine_state + 2*PI/3);
    Tlc.update();
  }
}
