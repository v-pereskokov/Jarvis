#include "../include/Devices/Device.hpp"

namespace Jarvis {
  namespace Devices {
    Device::Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :_name(name), _port(portName, portRate) {}
  }
}
