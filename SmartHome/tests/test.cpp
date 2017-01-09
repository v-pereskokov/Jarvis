#include <iostream>
#include <string>
#include <queue>
#include "../include/SerialPort.hpp"
#include "../include/Arduino/Arduino.hpp"

int main() {
//  Jarvis::Arduino::Connection::SerialPort serial("/dev/tty.HC-06-DevB", 9600);
  std::queue<Jarvis::Arduino::Arduino *> devices;
  devices.push(new Jarvis::Arduino::Arduino("Bulb", "/dev/cu.Bulb-DevB", 9600));
  while (true) {
    std::cout << "print cmd: ";
    std::string cmd;
    std::cin >> cmd;
    devices.front()->send(cmd);
  }
  delete devices.front();
  return 0;
}
