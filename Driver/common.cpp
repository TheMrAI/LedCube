#include "common.h"
#include "Arduino.h"


common::Config::Config(const int layer_count, const int* layer_pins, const int min_brightness,
      const int max_brightness, const int left_button, const int right_button, const int speed_pot,
      const int bright_pot):
      layer_count{layer_count},
      layer_pins{layer_pins},
      min_brightness{min_brightness},
      max_brightness{max_brightness},
      left_button{left_button},
      right_button{right_button},
      speed_pot{speed_pot},
      bright_pot{bright_pot}
      {}


void common::prime_layer(const int layer_id, const int layer_count, const int* layer_pins)
{
  for (int i = 0; i < layer_count; ++i)
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

long common::read_pot(const int pot_pin, const long min_value, const long max_value)
{
  int pot_value = analogRead(pot_pin);
  return map(pot_value, 0, 820, min_value, max_value);
}
