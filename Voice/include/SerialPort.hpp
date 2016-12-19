#ifndef SERIALPORT_H
#define SERIALPORT_H

#pragma once

#include <string>
#include <boost/utility.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>

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
    /*!
     * \namespace Connection
     * \brief Для подключения к Arduino
     */
    namespace Connection {
#define methods
#define params
      
      using namespace boost::asio;
      
      /*! \class SerialPort
       * \brief Класс для подключения по порту
       */
      class SerialPort : boost::noncopyable {
        /*!
         * \using io_service serviceIO
         * \brief Определяет тип для сервиса I/O
         */
        using serviceIO = io_service;
        /*!
         * \using serial_port port
         * \brief Определяет тип для порта
         */
        using port = serial_port;
        /*!
         * \using std::string portName
         * \brief Определяет тип для имени порта
         */
        using portName = std::string;
        /*!
         * \using size_t portRate
         * \brief Определяет тип для скорости передачи данных
         */
        using portRate = size_t;
        /*!
         * \using char byte
         * \brief Определяет тип для байта
         */
        using byte = char;
        /*!
         * \using std::strin message
         * \brief Определяет тип для сообщения
         */
        using message = std::string;
        
      public methods:
        /*!
         * \brief Конструктор
         * \param name Имя порта для подключения
         * \param rate Сокрость передачи данных
         */
        SerialPort(const portName &name, const portRate rate);
        /*!
         * \brief Деструктор
         */
        ~SerialPort() = default;
        /*!
         * \brief Метод для отправки сообщения
         * \param message Сообщение
         */
        void write(const message &message);
        /*!
         * \brief Метод для получения сообщения
         * \return message Сообщение
         */
        message read();
        
      private methods:
        SerialPort(const SerialPort &copy) = delete;
        SerialPort(const SerialPort &&copy) = delete;
        SerialPort& operator=(const SerialPort &copy) = delete;
        /*!
         * \brief Заполнение информацией
         * \param port Порт для "общения"
         * \param rate Скорость для передачи данных
         */
        void setRate(port &port, const portRate rate);
        
      private params:
        serviceIO _service; /*!< I/O cервис*/
        port _port; /*!< порт*/
      };
    }
  }
}

#endif // SERIALPORT_H
