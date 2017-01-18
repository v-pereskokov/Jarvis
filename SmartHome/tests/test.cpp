#include <iostream>
#include <string>
#include <queue>
#include <memory>
#include <chrono>
#include <thread>
#include "../include/SerialPort.hpp"
#include "../include/Devices/Devices.hpp"
#include "../include/BluetoothHC05.hpp"

void test1() {
  std::queue<std::unique_ptr<Jarvis::Connection::SerialPort>> devices;
  devices.push(std::unique_ptr<Jarvis::Connection::SerialPort>(new Jarvis::Connection::SerialPort("/dev/cu.usbmodem14331")));
  devices.front()->connect();
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    devices.front()->write("init");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "answer:\n";
    std::string answer = "hello";
    while (answer != "OK") {
      answer = devices.front()->read();
      std::cout << answer << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    devices.front()->write("link_2016,6,227738");
    std::this_thread::sleep_for(std::chrono::milliseconds(9000));
    std::cout << "answer:\n";
    answer = "hello";
    while (answer != "OK") {
      answer = devices.front()->read();
      std::cout << answer << std::endl;
    }
  }
}

void test2() {
  Jarvis::Devices::Bulb bulb("bulb1", "/dev/cu.RemoteControl-DevB");
  bulb.connect();
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

void test4() {
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
    } else if (cmd == "prev") {
      device->previously();
    } else {
      device->manual(cmd);
    }
  }
  delete factory;
}

void test5() {
  std::unique_ptr<Jarvis::Connection::SerialPort> port(new Jarvis::Connection::SerialPort("/dev/cu.usbmodem14331"));
  port->connect();
  std::this_thread::sleep_for(std::chrono::milliseconds(1600));
  port->write("init");
  std::cout << "answer:\n";
  std::string answer = "hello";
  while (answer != "OK") {
    answer = port->read();
    std::cout << answer << std::endl;
  }
  port->disconnect();
  port->connect();
  std::this_thread::sleep_for(std::chrono::milliseconds(1600));
  port->write("init");
  std::cout << "answer:\n";
  answer = "hello";
  while (answer != "OK") {
    answer = port->read();
    std::cout << answer << std::endl;
  }
  port->write("link_2016,6,227738");
  std::cout << "answer:\n";
  answer = "hello";
  while (answer != "OK") {
    answer = port->read();
    std::cout << answer << std::endl;
  }
  port->write("disc");
  std::cout << "answer:\n";
  answer = "hello";
  while (answer != "OK") {
    answer = port->read();
    std::cout << answer << std::endl;
  }
  port->disconnect();
}

void test6() {
  Jarvis::Connection::Bluetooth::BluetoothHC05 BTModule("/dev/cu.usbmodem14331");
  BTModule.connect();
//  std::cout << BTModule.getNameDevice("2016,6,227738") << std::endl;
//  BTModule.getListDevicesName();
  auto list = BTModule.getListOfDevicePortName();
  for (auto &i : list) {
    std::cout << "name: " << i.first << " port: " << i.second << std::endl;
  }
  BTModule.disconnect();
}

int main() {
  //  test1();
  //  test2();
  //  test3();
  //  test4();
  //  test5();
  test6();
  return 0;
}
