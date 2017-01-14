#include "../include/Devices/Teapot.hpp"
#include <iostream>

namespace Jarvis {
  namespace Devices {
    Teapot::Teapot(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    Device::command Teapot::makeRequest(const Device::command &command) const {
      return command; // name + "_" + cmd
    }
  }
}
