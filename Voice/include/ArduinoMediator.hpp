#ifndef ARDUINOMEDIATOR_H
#define ARDUINOMEDIATOR_H

#pragma once

#include <string>
#include <vector>
#include "Mediator.hpp"
#include "../src/SerialPort.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Mediator
   * \brief namespace для классов посредников
   */
  namespace Mediator {
#define methods
#define params
#define structs
    
    class ArduinoMediator : Mediator {
      /*!
       * \using Arduino::Connection::SerialPort SerialPort
       * \brief Определяет тип для порта I/O
       */
      using SerialPort = Arduino::Connection::SerialPort;
      
      public methods:
      ArduinoMediator() = default;
      
      /*!
       * \brief Статический метод для запуска скрипта
       * \return stringVoice Строка, преобразованная из голоса
       */
      stringVoice toArduino();
      
      private methods:
      /*!
       * \brief Метод для "общения" с портом Arduino
       * \param serial Порт, по которому будет отправлен сигнал
       * \param command Команда, которая будет отправлена
       */
      void sendToSerialPort(SerialPort &serial, const std::string &command);
      
    };
  }
}

#endif // ARDUINOMEDIATOR_H
