#include "../include/Devices/Module.hpp"

namespace Jarvis {
  namespace Devices {
    Module::Module(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
  }
}
