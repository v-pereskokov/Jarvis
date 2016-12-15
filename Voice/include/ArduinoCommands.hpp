#ifndef ARDUINOCOMMAND_H
#define ARDUINOCOMMAND_H

#pragma once

#include <string>
#include <map>
#include <boost/utility.hpp>
#include "../src/Arduino.cpp"

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
      using stateMapcommand = std::map<State, command>;
      
      public methods:
      ArduinoCommands(const Arduino &arduino);
      ArduinoCommands(const ArduinoCommands &copy) = default;
      ArduinoCommands(const ArduinoCommands &&copy) = default;
      ArduinoCommands& operator=(const ArduinoCommands &copy) = default;
      ~ArduinoCommands() = default;
      
      void command(const State &state);
      void command(const command &command);
      
      private map:
      stateMapcommand _states{{State::off, "off"}, {State::on, "on"}}
      
      private params:
      Arduino _arduino;
    };
  }
}

#endif // ARDUINOCOMMAND_H
