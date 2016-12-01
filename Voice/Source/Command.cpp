#include "../Include/Command.hpp"

namespace Jarvis {
  namespace Commands {
    
    void Command::execute(const CommandType::commandType &type, const scriptName &script, const argumentsList arguments) {
      argumentsVector list(arguments);
      list.emplace(list.begin(), script);
      list.emplace(list.begin(), type);
      terminalExecute(list);
    }
    
    void Command::terminalExecute(const argumentsVector &arguments) {
      executeCommand command;
      for (auto &it : arguments) {
        command += " " + it;
      }
      system(command.c_str());
    }
  }
}
