#include <iostream>
#include <string>
#include <queue>
#include <memory>
#include "../include/SerialPort.hpp"
#include "../include/Devices/Devices.hpp"

int main() {
//  std::queue<std::unique_ptr<Jarvis::Connection::SerialPort>> devices;
//  devices.push(std::unique_ptr<Jarvis::Connection::SerialPort>(new Jarvis::Connection::SerialPort("/dev/cu.Bulb-DevB")));
//  while (true) {
//    std::cout << "print cmd: ";
//    std::string cmd;
//    std::cin >> cmd;
//    devices.front()->write(cmd);
//  }
  Jarvis::Devices::Bulb bulb("bulb1", "/dev/cu.Bulb-DevB");
  while (true) {
    std::cout << "print cmd: ";
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "on") {
      bulb.on();
    } else if (cmd == "off") {
      bulb.off();
    } else {
      bulb.manual(cmd);
    }
  }
  return 0;
}
