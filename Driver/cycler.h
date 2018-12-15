#ifndef __CYCLER_HEADER__
#define __CYCLER_HEADER__

#include "common.h"

class ColorCycler
{
private:
  const common::Config& configuration;
public:
  ColorCycler(const common::Config& configuration);
  void simulate();
};

#endif //__CYCLER_HEADER__
