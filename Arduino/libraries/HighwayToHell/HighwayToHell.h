#ifndef HIGHWAYTOHELL_H
#define HIGHWAYTOHELL_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class HighwayToHell {
public:
  HighwayToHell();
  void high();
  void low();
  void play();
};

#endif // HIGHWAYTOHELL_H
