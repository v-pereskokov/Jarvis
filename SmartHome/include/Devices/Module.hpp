#ifndef MODULE_H
#define MODULE_H

#pragma once

#include "Device.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
#define usings
    
    class Module : public Device {
      protected usings:
      using scale = std::string;
      
      public methods:
      Module(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      virtual ~Module() = default;
      
      private methods:
      void on() override;
      void off() override;
    };
  }
}

#endif // MODULE_H
