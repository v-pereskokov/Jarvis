#ifndef EASYA_H
#define EASYA_H

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <StandardCplusplus.h>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <utility.h>
#include <map>

using size_t = unsigned int;

template <class Serial>
std::string readStream(const Serial &serial) {
  std::string command = "";
  if (serial.available()) {
    while (serial.peek() != -1) {
      command += char(serial.read());
      delay(2);
    }
    return command;
  }
}

struct ATCommands {
#define methods
#define params
  using key = std::string;
  using data = std::string;
  using KDPair = std::pair<key, data>;
  using ATMap = std::map<key, data>;
  using argument = std::string;
  using vectorCommands = std::vector<std::string>;
  using command = std::string;
  
  public methods:
  ATCommands();
  ~ATCommands() = default;
  
  data& operator[](const key &key);
  command getCommand(const command &command);
  
  private methods:
  void initialaize();
  std::pair<bool, ATCommands::key> checkCommand(const command &command);
  bool findCommandWithArgs(const command &command);
  command findArgument(const command &command);
  
  private params:
  ATMap _commands;
  vectorCommands _commandsWithArgs{"inqm", "pair", "link", "cmode", "rname"};
};

#endif // EASYA_H
