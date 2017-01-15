#include "BluetoothHC05.h"

#define PGM_STRING_MAPPED_TO_RAM(name, src) \
static const char name##_pgm[] PROGMEM = src; \
char name[sizeof(name##_pgm)]; \
strcpy_P(name, name##_pgm);

BluetoothHC05::BluetoothHC05(const PIN &rx, const PIN &tx, const PIN &key)
:_btModule(rx, tx), _key(key) {
  pinSetup(_key);
  _btModule.begin(38400);
}

void BluetoothHC05::check() {
  writeCommand("NAME?");
}

void BluetoothHC05::wait(const HardwareSerial &serial) {
  checkUpdate(_btModule, serial);
}

void BluetoothHC05::command(const buffer command) {
  writeCommand(command);
}

void BluetoothHC05::pinSetup(const PIN &pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void BluetoothHC05::writeCommand(const buffer command) {
  PGM_STRING_MAPPED_TO_RAM(AT, "AT");
  write(AT);
  if (command) {
    write("+");
    write(command);
  }
  PGM_STRING_MAPPED_TO_RAM(EOL, "\r\n");
  write(EOL);
}

void BluetoothHC05::write(const buffer command) {
  _btModule.write(command);
}
