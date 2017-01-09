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
  
  using PIN = int;
  using frequency = int;
  using brightness = int;
  
  public methods:
  Led(const PIN pin);
  void on();
  void off();
  void manual(const brightness bright);
  void blink(const frequency frequency);
  
  private methods:
  bool check(const brightness bright);
  
  private params:
  PIN _pin;
};

#endif // LED_H
