#include <Device.h>

Device device(4);

void setup() {
  Serial.begin(9600);
}

int cmd;

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();
  }
  switch (cmd) {
    case 0:
      device.off();
      break;
     case 1:
      device.on();
      break;
     case 2:
      Serial.write(device.state());
      break;
     default:
      break;
  }
}
