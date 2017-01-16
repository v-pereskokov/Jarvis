#include <EasyA.h>
#include <Device.h>
#include <SoftwareSerial.h>

Device device(13);
SoftwareSerial BTModule(10, 11);
std::string command = "";

void setup() {
  BTModule.begin(9600);
}

void loop() {
  if (BTModule.available()) {
    command = readStream(BTModule);
    if (command == "on") {
      device.on();
      BTModule.println("OK");
    } else if (command == "off") {
      device.off();
      BTModule.println("OK");
    }
  }
}
