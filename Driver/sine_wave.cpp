#include "sine_wave.h"
#include "Tlc5940.h"

const double step_size = (2*PI / 16); //offset each led a bit for a wavy effect

Sinewave::Sinewave(int start_layer=0, int end_layer, double max_brightness): start_layer{start_layer}, end_layer{end_layer}, max_brightness{max_brightness}
{}

void Sinewave::simulate(double duration)
{
  int actual_time = millis();
  int previous_time = millis();
  double sine_step = 2*PI / duration;
  double sine_prev_state = 0.0;
  double sine_actual_state = 0.0;
  while(true)
  {
    actual_time = millis();
    double delta_time = actual_time - previous_time;
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
    int led_brightness = (sin(sine_state + i*step_size)+1) * max_brightness;
    Tlc.set(i, led_brightness);
  }
}

void Sinewave::wave(double sine_state)
{
  for (int layer = start_layer; layer < end_layer; ++layer)
  {
    common::prime_layer(layer);
    color(0, 16, sine_state);
    color(16, 32, sine_state + PI/3);
    color(32, 48, sine_state + 2*PI/3);
    Tlc.update();
  }
}
