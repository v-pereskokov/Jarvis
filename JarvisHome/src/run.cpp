#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <queue>
#include "../../Jarvis/include/Jarvis.hpp"
#include "../../Jarvis/include/Voice.hpp"
#include "../../SmartHome/include/Devices/Devices.hpp"
#include "../../SmartHome/include/SerialPort.hpp"

#define SUCCESS 0

std::string wait() {
  
}

int run() {
  while (true) {
    if (wait == "record") {
      std::string voice = Jarvis::Jarvis::getStringVoice();
      
      
    }
  }
  return SUCCESS;
}



