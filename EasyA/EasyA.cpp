#include "EasyA.h"

std::string readStream() {
  std::string command = "";
  if (Serial.available()) {
    while (Serial.peek() != -1) {
      command += char(Serial.read());
      delay(2);
    }
    return command;
  }
}

ATCommands::ATCommands() {
  initialaize();
}

ATCommands::data& ATCommands::operator[](const key &key) {
  return _commands[key];
}

ATCommands::command ATCommands::getCommand(const command &command) {
  if (checkCommand(command)) {
    auto currentCommand = (*this)[command];
    return findCommandWithArgs(command) ? currentCommand + findArgument(command) : currentCommand;
  }
}

void ATCommands::initialaize(){
  _commands.insert(KDPair("name", "NAME?"));
  _commands.insert(KDPair("inqm", "INQM="));
  _commands.insert(KDPair("init", "INIT"));
  _commands.insert(KDPair("inq", "INQ"));
  _commands.insert(KDPair("pair", "PAIR="));
  _commands.insert(KDPair("link", "LINK="));
  _commands.insert(KDPair("disc", "DISC"));
}

bool ATCommands::checkCommand(const command &command) {
  for (auto &i : _commands) {
    if (command.find(i.first) != std::string::npos) { // SFINAE
      return true;
    }
  }
  return false;
}

bool ATCommands::findCommandWithArgs(const command &command) {
  for (auto &i : _commandsWithArgs) {
    if (command.find(i) != std::string::npos) {
      return true;
    }
  }
  return false;
}

ATCommands::command ATCommands::findArgument(const command &command) {
  return std::string(command.begin() + command.find("_") + 1, command.end());
}
