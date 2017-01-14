#include "BluetoothHC05.h"

BluetoothHC05::BluetoothHC05(const PIN &rx, const PIN &tx, const PIN &key)
:_btModule(rx, tx), _key(key) {
  keySetup(_key);
  _btModule.begin(38400);
}

BluetoothHC05::bluetooth BluetoothHC05::getBTSerial() const {
  return _btModule;
}

void BluetoothHC05::check() {
  _btModule.write("AT\r\n");
}

void BluetoothHC05::wait(const HardwareSerial &serial) {
  checkUpdate(_btModule, serial);
  checkUpdate(serial, _btModule);
}

void BluetoothHC05::keySetup(const PIN &key) {
  pinMode(key, OUTPUT);
  digitalWrite(key, HIGH);
}
