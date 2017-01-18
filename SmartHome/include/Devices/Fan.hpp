#ifndef FAN_H
#define FAN_H

#pragma once

#include <string>
#include <exception>
#include "Device.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define structs
    
    class Fan : public Device {
      public methods:
      Fan(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      ~Fan() = default;
      
      private methods:
      Device::command makeRequest(const Device::command &command) const;
    };
  }
}

#endif // FAN_H
