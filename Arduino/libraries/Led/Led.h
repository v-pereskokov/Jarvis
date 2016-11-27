#ifndef LED_H
#define LED_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Led {
#define methods
#define params
  
  typedef int PIN;
  
public methods:
  Led(PIN pin);
  void on();
  void off();
  void blink();
  
private params:
  PIN _pin;
};

#endif // LED_H
