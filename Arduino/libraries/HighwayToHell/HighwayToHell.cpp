#include "HighwayToHell.h"

HighwayToHell::HighwayToHell() {
  Serial.begin(9600);
}

void high(const int pin) {
  digitalWrite(pin, HIGH);
}
