#ifndef DEVICE_H
#define DEVICE_H

#pragma once

#include <string>
#include "../SerialPort.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define usings
    
    class Device {
      protected usings:
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
      using command = std::string;
      friend class DeviceFactory;
      
      public methods:
      Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      virtual ~Device() = default;
      
      virtual void on() = 0;
      virtual void off() = 0;
      virtual void execute(const command &command) = 0;
      
      private methods:
      Device() = delete;
      Device(const Device &copy) = delete;
      Device(Device &&copy) = delete;
      Device& operator=(const Device &copy) = delete;
      Device& operator=(Device &&copy) = delete;
      
      
      protected params:
      name _name; /*!< имя устройства*/
      port _port; /*!< порт подключения*/
    };
  }
}

#endif // DEVICE_H
