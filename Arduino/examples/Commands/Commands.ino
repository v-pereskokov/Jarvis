#include <Led.h>
#include <HighwayToHell.h>

#define button A5

const int pin10 = 10;
const int pin9 = 9;

Led led10(pin10);
Led led9(pin9);
HighwayToHell rock(pin9);

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
      led10.off();
      led9.off();
      blueOff();
      break;
    case 1:
      led10.on();
      led9.on();
      break;
    case 2:
      led10.blink();
      led9.blink();
      break;
    case 3:
      rock.play();
      break;
    default:
      Serial.print("nothing");
      break; 
  }
}

