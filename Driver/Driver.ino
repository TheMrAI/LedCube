#include "math.h"
#include "Tlc5940.h"
#include "sine_wave.h"
#include "cycler.h"

const double duration = 5000;
const int layer_count = 4;
const int layer_pins[layer_count] = {4, 5, 6 ,7};
const double min_brightness = 0;
const double max_brightness = 4095;
const int left_button = 8;
const int right_button = 2;
const int speed_pot = 4;
const int bright_pot = 3;

common::Config configuration
  (
    layer_count,
    layer_pins,
    min_brightness,
    max_brightness,
    left_button,
    right_button,
    speed_pot,
    bright_pot
  );

void setup()
{
  Tlc.init();
  Serial.begin(9600);
}

void loop()
{
  ColorCycler cycler{configuration};
  cycler.simulate();
}
