#include <EasyA.h>
#include <Device.h>

Device device(13);
std::string command = "";

void setup() {
  Serial.begin(9600); // baud 9600, no line ending
}

void loop() {
  if (Serial.available()) {
    command = readStream();
    Serial.println(command.c_str());
    delay(10);
    if (command[0] == '$') {
      auto cmdUno = command.erase(0, 1);
      Serial.println(cmdUno.c_str()); // to uno
      if (cmdUno == "on") {
        device.on();
      } else if (cmdUno == "off") {
        device.off();
      }
    }
  }
}
