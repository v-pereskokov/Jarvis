#include "../include/Devices/Fan.hpp"

namespace Jarvis {
  namespace Devices {
    Fan::Fan(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    Device::command Fan::makeRequest(const Device::command &command) const {
      return command; // name + "_" + cmd
    }
  }
}
