#ifndef COMMAND_H
#define COMMAND_H

#pragma once

#include <vector>
#include <initializer_list>

namespace Jarvis {
  namespace Commands {
    namespace CommandType{
      using commandType = std::string;
      
      const commandType python = "python";
      const commandType shell = "";
      const commandType music = "afplay";
    }
#define methods
#define params
    
    class Command final {
      using scriptName = std::string;
      using argument = std::string;
      using argumentsList = std::initializer_list<argument>;
      using argumentsVector = std::vector<argument>;
      using executeCommand = std::string;
      
    public:
      static void execute(const CommandType::commandType &type, const scriptName &script, const argumentsList arguments);
      
    private:
      static void terminalExecute(const argumentsVector &arguments);
    };
  }
}

#endif // COMMAND_H
