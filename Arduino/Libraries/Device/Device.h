#ifndef DEVICE_H
#define DEVICE_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Device {
#define methods
#define params
  
  using PIN = int;
  using frequency = int;
  using brightness = int;
  using states = char;
  
  public methods:
  Device(const PIN pin);
  void on();
  void off();
  void manual(const brightness bright);
  void blink(const frequency frequency);
  states state();
  
  private methods:
  bool check(const brightness bright);
  
  private params:
  PIN _pin;
};

#endif // DEVICE_H
