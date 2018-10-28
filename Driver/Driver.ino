#include "math.h"
#include "Tlc5940.h"

int layer_pins[] = {4, 5, 6 ,7};

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

void setup() 
{
  Tlc.init();
}

void loop() 
{
  int maxBrightness = 2047; // 4095
  int duration = 1000;
  double step_size = (2*PI / 16);
  for (double sine_state = 0.0; sine_state < 2*PI; sine_state += step_size)
  {
    for (int layer = 0; layer < 4; ++layer)
    {
      prime_layer(layer);
      for (int i = 0; i < 16; ++i)
      {
        int brightness = (sin(sine_state + i*step_size)+1) * (maxBrightness/2);
        Tlc.set(i, brightness);
      }
      Tlc.update();
    }
    delay(duration / 16);
  }
}
