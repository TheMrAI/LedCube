#include "math.h"
#include "Tlc5940.h"
#include "tlc_fades.h"

int layer0 = 0;
int layer1 = 1;
int layer2 = 2;
int layer3 = 3;

void setup() {
  Tlc.init();
  Serial.begin(9600);
}

void loop() {
  int duration = 1000;
  double step_size = (2*PI / 16);
  for (double sine_state = 0.0; sine_state < 2*PI; sine_state += step_size)
  {
   for (int i = 0; i < 16; ++i)
   {
      int brightness = (sin(sine_state + i*step_size)+1) * (4095/2);
      Tlc.set(i, brightness);
   }
   Tlc.update();
   delay(duration / 16);
  }
}
