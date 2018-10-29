#include "common.h"
#include "Arduino.h"

void common::prime_layer(int layer_id)
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
