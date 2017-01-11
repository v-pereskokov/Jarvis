#include "../include/Devices/Bulb.hpp"
#include <iostream>

namespace Jarvis {
  namespace Devices {
    Bulb::Bulb(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    void Bulb::manual(const Device::command &command) {
      execute(command);
    }
    
    void Bulb::execute(const Device::command &command) {
      _port.write(command);
    }
    
    Device::command Bulb::makeRequest(const Device::command &command) const {
      return command; // name + "_" + cmd
    }
  }
}
