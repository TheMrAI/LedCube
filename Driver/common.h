#ifndef __COMMON_HEADER__
#define __COMMON_HEADER__

namespace common 
{
  class Config
  {
    public:
      const int layer_count;
      const int* layer_pins;
      const int min_brightness;
      const int max_brightness;
      const int left_button;
      const int right_button;
      const int speed_pot;
      const int bright_pot;

      Config(const int layer_count, const int* layer_pins, const int min_brightness, const int max_brightness, const int left_button, const int right_button, const int speed_pot,
      const int bright_pot);
  };

  void prime_layer(const int layer_id, const int layer_count, const int* layer_pins);

  long read_pot(const int pot_pin, const long min_value, const long max_value);
}

#endif //__COMMON_HEADER__
