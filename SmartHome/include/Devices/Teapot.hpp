#ifndef TEAPOT_H
#define TEAPOT_H

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
    
    class Teapot : public Device {
      public methods:
      Teapot(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      ~Teapot() = default;
      
      private methods:
      Device::command makeRequest(const Device::command &command) const;
    };
  }
}

#endif // TEAPOT_H
