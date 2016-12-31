#ifndef COMMANDS_H
#define COMMANDS_H

#pragma once

#include <string>
//shared_ptr
#include <boost/utility.hpp>
#include "../src/ArduinoCommands.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Arduino
   * \brief Для работы с Arduino
   */
  namespace Arduino {
#define methods
#define params
    
    class Commands {
      public methods:
      virtual ~Commands() = default;
      virtual void execute(ArduinoCommands::command *command = "") = 0;
      
      protected methods:
      Commands(const ArduinoCommands *arduino);
      
      private methods:
      Commands() = delete;
      
      protected params:
      ArduinoCommands *_arduino;
    };
    
    class CommandOff : Commands {
      public methods:
      CommandOff(const ArduinoCommands *arduino);
      void execute(const ArduinoCommands::command &command = "") override;
    };
    
    class CommandOn : Commands {
      public methods:
      CommandOn(const ArduinoCommands *arduino);
      void execute(const ArduinoCommands::command &command = "") override;
    };
    
    class CommandOther : Commands {
      public methods:
      CommandOther(const ArduinoCommands *arduino);
      void execute(const ArduinoCommands::command &command = "") override;
    };
  }
}

#endif // COMMANDS_H
