#include "Device.h"

Device::Device(const PIN pin)
:_pin(pin) {
  pinMode(_pin, OUTPUT);
}

void Device::on() {
  digitalWrite(_pin, HIGH);
}

void Device::off() {
  digitalWrite(_pin, LOW);
}

void Device::manual(const brightness bright) {
  if (check(bright)) {
    digitalWrite(_pin, bright);
  }
}

void Device::blink(const frequency frequency) {
  on();
  delay(frequency);
  off();
  delay(frequency);
}

Device::states Device::state() {
  return digitalRead(_pin) == HIGH ? 'h' : 'l';
}

bool Device::check(const brightness bright) {
  return bright >= LOW && bright <= HIGH;
}
