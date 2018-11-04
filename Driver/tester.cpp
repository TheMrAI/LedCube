#include "tester.h"
#include "common.h"
#include "Tlc5940.h"

ColorCycler::ColorCycler()
{}

void ColorCycler::simulate(int duration)
{
  int sub_cycle_duration = duration / 3;
  while(true)
  {
    for(int color = 0; color < 3; ++color)
    {
      Tlc.clear();
      unsigned long start_millis = millis();
      unsigned long end_millis = start_millis + sub_cycle_duration;
      while(millis() < end_millis)
      {
        for(int layer = 0; layer < common::layer_count; ++layer)
        {
          common::prime_layer(layer);
          for(int i = color * 16; i < (color + 1) * 16 ; ++i)
          {
            Tlc.set(i, common::maxBrightness);
          }
          Tlc.update();
        }
      }  
    }  
  }
}
