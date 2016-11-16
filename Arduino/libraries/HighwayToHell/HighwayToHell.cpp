#include "HighwayToHell.h"

HighwayToHell::HighwayToHell(const PIN pin)
:_pin(pin) {
  pinMode(_pin, OUTPUT);
}

void HighwayToHell::play() {
  music();
}

void HighwayToHell::high() {
  digitalWrite(_pin, HIGH);
}

void HighwayToHell::low() {
  digitalWrite(_pin, LOW);
}

void HighwayToHell::dot() {
  high();
  delay(150);
  low();
  delay(150);
}

void HighwayToHell::music() {
  delay(900);
  dot(); dot(); dot();
  delay(1200);
  dot(); dot(); dot();
  delay(1200);
  dot(); dot(); dot();
  delay(260);
  dot(); dot(); dot();
  delay(220);
  dot();
  delay(190);
  dot(); dot();
}
