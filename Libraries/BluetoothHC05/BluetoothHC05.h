#ifndef BLUETOOTHHC05_H
#define BLUETOOTHHC05_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SoftwareSerial.h>
#include <avr/pgmspace.h>

class BluetoothHC05 {
#define methods
#define params
  using bluetooth = SoftwareSerial;
  using PIN = int;
  using buffer = char*;
  
  public methods:
  BluetoothHC05(const PIN &rx, const PIN &tx, const PIN &power, const PIN &key);
  ~BluetoothHC05() = default;
  
  void check();
  void wait(const HardwareSerial &serial);
  void command(const buffer command);
  void write(const buffer command);
  void reset();
  
  private methods:
  BluetoothHC05() = delete;
  BluetoothHC05(const BluetoothHC05 &copy) = delete;
  BluetoothHC05& operator=(const BluetoothHC05 &copy) = delete;
  
  void pinSetup(const PIN &pin);
  void writeCommand(const buffer command);
  
  private params:
  bluetooth _btModule;
  PIN _power;
  PIN _key;
};

template <class FirstSerial, class SecondSerial>
void checkUpdate(const FirstSerial &lhs, const SecondSerial &rhs) {
  while (lhs.available()) {
    rhs.write(lhs.read());
  }
}

#endif // BLUETOOTHHC05_H
