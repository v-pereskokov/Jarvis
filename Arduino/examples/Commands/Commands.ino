#include <Led.h>

#define button A5

const int red = 11;
const int green = 12;
const int blue = 13;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void redOn() {
  digitalWrite(red, HIGH);
}

void redOff() {
  digitalWrite(red, LOW);
}

void greenOn() {
  digitalWrite(green, HIGH);
}

void greenOff() {
  digitalWrite(red, LOW);
}

void blueOn() {
  digitalWrite(blue, HIGH);
}

void blueOff() {
  digitalWrite(blue, LOW);
}

int cmd;
 
void loop() {
  if (digitalRead(button) == LOW) {
    redOn();
    Serial.print("record\n");
    delay(5000);
    redOff();
    blueOn();
    delay(6000);
  } else if (Serial.available()) {
    cmd = int(Serial.read()) - 48;
    Serial.print("command: ");
    Serial.print(cmd);
    Serial.print("\n");
  }
  switch (cmd) {
    case 0:
      blueOff();
      break;
    default:
      break; 
  }
}

