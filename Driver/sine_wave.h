#include "common.h"

class Sinewave
{
public:
  Sinewave(int start_layer=0, int end_layer=common::layer_count, double max_brightness=common::maxBrightness);
  void simulate(double duration=5000);
  void color(int channel_start, int channel_end, double sine_state);
  void wave(double sine_state);

private:
  double max_brightness;
  int start_layer;
  int end_layer;
};
