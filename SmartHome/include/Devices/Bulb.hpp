#ifndef BULB_H
#define BULB_H

#pragma once

#include <string>
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
    
    class Bulb : public Device {
      
      using command = std::string;
      
      public methods:
      Bulb(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      
      void on() override;
      void off() override;
      void manual(const command &command);
      Device::name getName() const;
      
      ~Bulb() = default;
      
      private methods:
      void send(const command &command);
      Device::signal makeRequest(const command &command) const;
    };
  }
}

#endif // BULB_H
