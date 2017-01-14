#ifndef BLUETOOTHHC05_H
#define BLUETOOTHHC05_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SoftwareSerial.h>

class BluetoothHC05 {
#define methods
#define params
  using bluetooth = SoftwareSerial;
  using PIN = int;
  
  public methods:
  BluetoothHC05(const PIN &rx, const PIN &tx, const PIN &key);
  ~BluetoothHC05() = default;
  
  bluetooth getBTSerial() const;
  void check();
  void getName() const;
  void wait(const HardwareSerial &serial);
  
  private methods:
  BluetoothHC05() = delete;
  BluetoothHC05(const BluetoothHC05 &copy) = delete;
  BluetoothHC05& operator=(const BluetoothHC05 &copy) = delete;
  
  void keySetup(const PIN &key);
  
  private params:
  bluetooth _btModule;
  PIN _key;
};

template <class FirstSerial, class SecondSerial>
void checkUpdate(const FirstSerial &lhs, const SecondSerial &rhs) {
  if (lhs.available()) {
    rhs.write(lhs.read());
  }
}

#endif // BLUETOOTHHC05_H
