#include "Led.h"

Led::Led(const PIN pin)
:_pin(pin) {
  pinMode(_pin, OUTPUT);
}

void Led::on() {
  digitalWrite(_pin, HIGH);
}

void Led::off() {
  digitalWrite(_pin, LOW);
}

void Led::blink() {
  on();
  delay(100);
  off();
  delay(100);
}
