#include <EasyA.h>
#include <BluetoothHC05.h>
#include <Stream.h>

BluetoothHC05 BTModule(10, 11, 9);
ATCommands at;
std::string command = "";

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(9600); // baud 9600, no line ending
}

void loop() {
  if (Serial.available()) {
    command = readStream();
    Serial.println(at.getCommand(command).c_str());
    if (command == "reset") {
      resetFunc();
    } else if (command[0] == '$') {
      ; // to uno
    } else {
      BTModule.command(at.getCommand(command).c_str());
    }
  }
  BTModule.wait(Serial);
}
