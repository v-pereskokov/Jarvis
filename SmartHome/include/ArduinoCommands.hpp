#ifndef ARDUINOCOMMAND_H
#define ARDUINOCOMMAND_H

#pragma once

#include <string>
#include <map>
#include <boost/utility.hpp>
#include "Arduino.hpp"
#include "../States.hpp"

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
#define map
    
    /*! \class ArduinoCommand
     * \brief Класс для управления платами Arduino
     */
    class ArduinoCommands {
      using command = std::string;
      using stateMapcommand = std::map<States, command>;
      
      friend class States<ArduinoCommands>;
      
      struct ArduinoStates {
        using ArduinoState = States<ArduinoCommands>;
        
        public methods:
        ArduinoStates() = default;
        
        ~ArduinoStates();
        
        public params:
        ArduinoState *_current{new Off()};
        ArduinoState *_previous{new Off()};
      };
      
      public methods:
      ArduinoCommands(const Arduino &arduino);
      ArduinoCommands(const ArduinoCommands &copy) = default;
      ArduinoCommands(const ArduinoCommands &&copy) = default;
      ArduinoCommands& operator=(const ArduinoCommands &copy) = default;
      ~ArduinoCommands() = default;
      
      ArduinoStates::ArduinoState getCurrentState() const;
      ArduinoStates::ArduinoState getPreviousState() const;
      void setCurrentState(const ArduinoStates::ArduinoState &state);
      void setPreviousState(const ArduinoStates::ArduinoState &state);
      void command(const command &command);
      
      private methods:
      command checkState(const command &command);
      
      private params:
      Arduino _arduino;
      ArduinoStates _states;
    };
  }
}

#endif // ARDUINOCOMMAND_H
