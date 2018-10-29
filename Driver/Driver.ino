#include "math.h"
#include "Tlc5940.h"
#include "sine_wave.h"

const double duration = 5000;

void setup()
{
  Tlc.init();
}

void loop()
{
  Sinewave sinewave{1, 3};
  sinewave.simulate(duration);
}
