#include "common.h"

class Sinewave
{
public:
  Sinewave(const common::Config& configuration);
  void simulate();
private:
  void color(int channel_start, int channel_end, double sine_state);
  void wave(double sine_state);

private:
  const common::Config& configuration;
};
