#ifndef ARDUINO_H
#define ARDUINO_H

#pragma once

#include <string>
#include <boost/utility.hpp>
#include "../src/SerialPort.cpp"

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
    
    /** \enum States
     * \brief Возможные состояния устройств
     */
    enum class States {
      off = 0, /*!< Выключенное состояние*/
      on, /*!< Включенное состояние*/
      other /*!< Иное состояние*/
    };
    
    /*! \class Arduino
     * \brief Класс - платы Arduino
     */
    class Arduino final {
      using Connection;
      /*!
       * \using Connection::SerialPort port
       * \brief Определяет тип для порта, по которому будут отправляться сигналы
       */
      using port = SerialPort;
      
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
      Ardiuno(const name &name, const SerialPort::portName &portName, const SerialPort::portRate rate);
      
      Ardiuno(const Ardiuno &copy) = default;
      Ardiuno(const Ardiuno &&copy) = default;
      Ardiuno& operator=(const Ardiuno &copy) = default;
      
      /*!
       * \brief Деструктор
       */
      ~Ardiuno() = default;
      
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
