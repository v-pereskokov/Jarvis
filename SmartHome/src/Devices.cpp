#include "../include/Devices/Devices.hpp"

namespace Jarvis {
  namespace Devices {
    DeviceFactory::DeviceFactory() {
      initialize();
    }
    
    DeviceFactory::uniqueDevice DeviceFactory::operator()(const deviceClassName &className, const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate) {
      auto find = _traits.find(className);
      if (find != _traits.end()) {
        return std::forward<uniqueDevice>(find->second->create(name, portName, portRate));
      } else {
        throw std::invalid_argument("Device not found!");
      }
    }
    
    void DeviceFactory::initialize() {
      _traits["Bulb"] = std::make_shared<Creator<Bulb, Device, Device::name, Connection::SerialPort::portName, Connection::SerialPort::portRate>>();
      _traits["Kettle"] = std::make_shared<Creator<Teapot, Device, Device::name, Connection::SerialPort::portName, Connection::SerialPort::portRate>>();
      _traits["Fan"] = std::make_shared<Creator<Fan, Device, Device::name, Connection::SerialPort::portName, Connection::SerialPort::portRate>>();
    }
  }
}
