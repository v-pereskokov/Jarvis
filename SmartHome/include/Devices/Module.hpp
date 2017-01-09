#ifndef DEVICE_H
#define DEVICE_H

#pragma once

#include <string>
#include "../Device.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define usings
    
    class Module : public Device {
      public methods:
      Module(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      
      virtual void on() = 0;
      virtual void off() = 0;
      
      virtual ~Module() = default;
      
      protected params:
      name _name; /*!< имя устройства*/
      port _port; /*!< порт подключения*/
    };
  }
}

#endif // DEVICE_H
