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

void manual(const brightness bright) {
  if (check(bright)) {
    digitalWrite(_pin, bright);
  }
}

void Led::blink(const frequency frequency) {
  on();
  delay(frequency);
  off();
  delay(frequency);
}

bool check(const brightness bright) {
  return bright >= LOW && bright <= HIGH;
}
