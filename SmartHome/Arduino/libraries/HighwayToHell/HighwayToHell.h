#ifndef HIGHWAYTOHELL_H
#define HIGHWAYTOHELL_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class HighwayToHell {
#define methods
#define params
  
  typedef int PIN;
  
public methods:
  HighwayToHell(PIN pin);
  void play();
  
private methods:
  void high();
  void low();
  void dot();
  void music();
  
private params:
  PIN _pin;
};

#endif // HIGHWAYTOHELL_H
