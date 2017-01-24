#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <map>
#include "../../Jarvis/include/Jarvis.hpp"
#include "../../Jarvis/include/Voice.hpp"
#include "../../SmartHome/include/Devices/Devices.hpp"
#include "../../SmartHome/include/SerialPort.hpp"

#define SUCCESS 0

Jarvis::Connection::SerialPort remote("/dev/cu.RemoteControl-DevB", 9600);
Jarvis::Devices::Bulb bulb("bulb1", "/dev/cu.Bulb-DevB", 9600);
Jarvis::Devices::Teapot kettle("kettle", "/dev/cu.Kettle-DevB", 9600);

std::map<std::string, std::string> commands{{"включи", "on"}, {"выключи", "off"}, {"включить", "on"}, {"выключить", "off"}, {"погаси", "off"}, {"вскипяти", "on"}, {"успокойся", "goodbye"}};
int hello = 0;

void letsTalk(const std::string &file) {
  std::string cmd = "afplay ../samples/" + file + ".wav";
  system(cmd.c_str());
}

void on(const std::string &command) {
  if (command.find("лампу") != std::string::npos || command.find("свет") != std::string::npos) {
    bulb.connect();
    bulb.on();
    bulb.disconnect();
  } else if (command.find("чайник") != std::string::npos) {
    kettle.connect();
    kettle.on();
    kettle.disconnect();
  }
}

void off(const std::string &command) {
  if (command.find("лампу") != std::string::npos || command.find("свет") != std::string::npos) {
    bulb.connect();
    bulb.off();
    bulb.disconnect();
  } else if (command.find("чайник") != std::string::npos) {
    kettle.connect();
    kettle.off();
    kettle.disconnect();
  }
}

void execute(const std::string &command) {
  auto findCmd = commands.begin();
  for (auto it = findCmd; it != commands.end(); ++it) {
    auto pos = command.find(it->first);
    if (pos != std::string::npos) {
      findCmd = it;
      break;
    }
  }
  findCmd->second == "on" ? on(command) : off(command);
  letsTalk("Success" + (hello == 0 ? "1" : std::to_string(1 + rand() % 2)));
}

void waiting() {
  while (remote.read() != "stop");
}

int run() {
  remote.connect();
  srand(42);
  while (true) {
    if (remote.read() == "record") {
      std::thread reading(waiting);
      reading.join();
      std::string command;
      std::string numb_welcome = "0";
      if (hello) {
        numb_welcome = std::to_string(1 + rand() % 2);
      }
      std::thread welcomeVoice(letsTalk, "Welcome" + numb_welcome);
      welcomeVoice.join();
      command = Jarvis::Jarvis::getStringVoice();
      std::cout << "command: " << command << std::endl;
      std::thread doVoice(letsTalk, "Doing" + std::to_string(1 + rand() % 2));
      std::thread doIt(execute, command);
      doVoice.join();
      doIt.join();
    }
  }
  remote.disconnect();
  return SUCCESS;
}



