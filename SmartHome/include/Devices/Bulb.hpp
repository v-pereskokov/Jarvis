#ifndef ARDUINO_H
#define ARDUINO_H

#pragma once

#include <string>
#include <boost/utility.hpp>
#include "../SerialPort.hpp"

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
#define structs
    
    /*! \class Arduino
     * \brief Класс - платы Arduino
     */
    class Arduino final {
      /*!
       * \using Connection::SerialPort port
       * \brief Определяет тип для порта, по которому будут отправляться сигналы
       */
      using port = Connection::SerialPort;
      
      /*!
       * \using std::string name
       * \brief Определяет тип для имени платы
       */
      using name = std::string;
      
      /*!
       * \using std::string signal
       * \brief Определяет тип для отправляемого сигнала
       */
      using signal = std::string;
      
      public methods:
      /*!
       * \brief Конструктор
       * \param name Имя платы
       * \param portName Имя порта для подключения
       * \param rate Сокрость передачи данных
       */
      Arduino(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate rate);
      
      Arduino(const Arduino &copy) = default;
      Arduino(Arduino &&copy) = default;
      Arduino& operator=(const Arduino &copy) = default;
      
      /*!
       * \brief Деструктор
       */
      ~Arduino() = default;
      
      /*!
       * \brief Метод для отправки сообщения
       * \param signal Сигнал
       */
      void send(const signal &signal);
      
      /*!
       * \brief Метод для получения сообщения
       * \return signal Сигнал
       */
      signal read();
      
      private params:
      name _name; /*!< имя платы*/
      port _port; /*!< порт подключения*/
    };
  }
}

#endif // ARDUINO_H
