#include "EasyA.h"

ATCommands::ATCommands() {
  initialaize();
}

ATCommands::data& ATCommands::operator[](const key &key) {
  return _commands[key];
}

ATCommands::command ATCommands::getCommand(const command &command) {
  auto check = checkCommand(command);
  if (check.first) {
    auto currentCommand = (*this)[check.second];
    return findCommandWithArgs(command) ? currentCommand + findArgument(command) : currentCommand;
  }
}

void ATCommands::initialaize(){
  _commands.insert(KDPair("rname", "RNAME?"));
  _commands.insert(KDPair("name", "NAME?"));
  _commands.insert(KDPair("inqm", "INQM="));
  _commands.insert(KDPair("init", "INIT"));
  _commands.insert(KDPair("inq", "INQ"));
  _commands.insert(KDPair("pair", "PAIR="));
  _commands.insert(KDPair("link", "LINK="));
  _commands.insert(KDPair("disc", "DISC"));
  _commands.insert(KDPair("role", "ROLE="));
  _commands.insert(KDPair("cmode", "CMODE="));
}

std::pair<bool, ATCommands::key> ATCommands::checkCommand(const command &command) {
  for (auto &i : _commands) {
    auto commandName(command);
    commandName.erase(commandName.begin() + (commandName.find("_") != std::string::npos ? commandName.find("_") : commandName.length()), commandName.end());
    if (i.first == commandName) { // SFINAE
      return {true, i.first};
    }
  }
  return {false, ""};
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
