#include "cycler.h"
#include "Tlc5940.h"

ColorCycler::ColorCycler(const common::Config& configuration): configuration{configuration}
{}

void ColorCycler::simulate()
{
  while (true)
  {
    int duration = common::read_pot(configuration.speed_pot, 2000, 5000);
    int sub_cycle_duration = duration / 3;
    int brightness = common::read_pot(configuration.bright_pot, configuration.min_brightness, configuration.max_brightness);
    for (int color = 0; color < 3; ++color)
    {
      Tlc.clear();
      unsigned long start_millis = millis();
      unsigned long end_millis = start_millis + sub_cycle_duration;
      while (millis() < end_millis)
      {
        for (int layer = 0; layer < configuration.layer_count; ++layer)
        {
          common::prime_layer(layer, configuration.layer_count, configuration.layer_pins);
          for (int i = color * 16; i < (color + 1) * 16 ; ++i)
          {
            Tlc.set(i, brightness);
          }
          Tlc.update();
        }
      }
    }
  }
}
