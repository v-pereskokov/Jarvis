#include <Led.h>
#include <HighwayToHell.h>

int pin = 13;

Led led(pin);
HighwayToHell rock(pin);


void setup() {
  Serial.begin(9600);
}

int cmd;
 
void loop() {
  if (Serial.available()) {
    cmd = int(Serial.read()) - 48;
    Serial.print("command: ");
    Serial.print(cmd);
    Serial.print("\n");
  }
  switch (cmd) {
    case 0:
      led.off();
      break;
    case 1:
      led.on();
      break;
    case 2:
      led.blink();
       break;
    case 3:
      rock.play();
      break;
    default:
      Serial.print("nothing");
      break; 
  }
}

