#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

void readAndWrite(const SoftwareSerial &lhs, const HardwareSerial &rhs) {
  if (lhs.available()) {
    rhs.write(lhs.read());
  }
}

void readAndWrite(const HardwareSerial &lhs, const SoftwareSerial &rhs) {
  if (lhs.available()) {
    rhs.write(lhs.read());
  }
}

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  readAndWrite(BTSerial, Serial);
  readAndWrite(Serial, BTSerial);
}

