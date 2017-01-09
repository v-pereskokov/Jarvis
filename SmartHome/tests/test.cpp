#include <iostream>
#include <string>
#include <queue>
#include <memory>
#include "../include/SerialPort.hpp"
#include "../include/Devices/Devices.hpp"

void test1() {
  std::queue<std::unique_ptr<Jarvis::Connection::SerialPort>> devices;
  devices.push(std::unique_ptr<Jarvis::Connection::SerialPort>(new Jarvis::Connection::SerialPort("/dev/cu.Bulb-DevB")));
  while (true) {
    std::cout << "print cmd: ";
    std::string cmd;
    std::cin >> cmd;
    devices.front()->write(cmd);
  }
}

void test2() {
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
}

//void test3() {
//  Jarvis::Devices::DeviceFactory *factory = new Jarvis::Devices::DeviceFactory("bulb", "/dev/cu.Bulb-DevB");
//  while (true) {
//    std::unique_ptr<Jarvis::Devices::Device> device;
//    std::cout << "enter the class: ";
//    std::string classname;
//    std::cin >> classname;
//    device = (*factory)(classname);
//    std::cout << "print cmd: ";
//    std::string cmd;
//    std::cin >> cmd;
//    if (cmd == "on") {
//      device->on();
//    } else if (cmd == "off") {
//      device->off();
//    }
//  }
//  delete factory;
//}

void test3() {
  Jarvis::Devices::DeviceFactory *factory = new Jarvis::Devices::DeviceFactory;
  std::unique_ptr<Jarvis::Devices::Device> device;
  std::cout << "enter the class name: ";
  std::string clname;
  std::cin >> clname;
  device = (*factory)(clname, "bulb1", "/dev/cu.Bulb-DevB");
  while (true) {
    std::cout << "print cmd: ";
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "on") {
      device->on();
    } else if (cmd == "off") {
      device->off();
    }
  }

  delete factory;
}

int main() {
  //  test1();
  //  test2();
  test3();
  return 0;
}
