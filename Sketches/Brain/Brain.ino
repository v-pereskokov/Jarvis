#include <EasyA.h>
#include <BluetoothHC05.h>

BluetoothHC05 BTModule(10, 11, 8, 9);
ATCommands at;
std::string command = "";

void setup() {
  Serial.begin(9600); // baud 9600, no line ending
}

void loop() {
  if (Serial.available()) {
    command = readStream(Serial);
    Serial.println(command.c_str());
    delay(10);
    if (command == "reset") {
      BTModule.reset();
    } else if (command == "on" || command == "off") {
      BTModule.write(command.c_str());
      delay(100);
    } else {
      Serial.println(at.getCommand(command).c_str());
      BTModule.command(at.getCommand(command).c_str());
    }
  }
  BTModule.wait(Serial);
}

