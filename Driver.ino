#include "math.h"
#include "Tlc5940.h"

int layer_pins[] = {4, 5, 6 ,7};
const double step_size = (2*PI / 16);
const double duration = 1000;
const int maxBrightness = 4095;

void prime_layer(int layer_id)
{
  for (int i = 0; i < 4; ++i)
  {
    if (i == layer_id)
    {
      analogWrite(layer_pins[i], 0); // ON
    }
    else
    {
      analogWrite(layer_pins[i], 255); // OFF
    }
  }
}

void sine_color(int channel_start, int channel_end, double sine_state)
{
  for (int i = channel_start; i < channel_end; ++i)
  {
    int brightness = (sin(sine_state + i*step_size)+1) * (maxBrightness/2);
    Tlc.set(i, brightness);
  }
}

void sine_wave(double sine_state)
{
  for (int layer = 0; layer < 4; ++layer)
  {
    prime_layer(layer);
    sine_color(0, 16, sine_state);
    sine_color(16, 32, sine_state + PI/3);
    sine_color(32, 48, sine_state + 2*PI/3);
    Tlc.update();
  }
}

void setup()
{
  Tlc.init();
}

void loop()
{
  for (double sine_state = 0.0; sine_state < 2*PI; sine_state += step_size)
  {
      //double sine_shift = color * (2*PI / 3.0);
      sine_wave(sine_state);
      delay(duration / 16);
  }
}
