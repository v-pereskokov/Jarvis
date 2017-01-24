#ifndef RADIO_H
#define RADIO_H

#pragma once

#include <string>
#include "Module.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
    
    class Radio : public Device {
      
      public methods:
      Radio(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      ~Radio() = default;

        private methods:
        Device::command makeRequest(const Device::command &command) const;
    };
  }
}

#endif // RADIO_H
