#include "../include/Devices/Devices.hpp"

namespace Jarvis {
  namespace Devices {
    DeviceFactory::DeviceFactory(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate) {
      initialize(name, portName, portRate);
    }
    
    DeviceFactory::uniqueDevice DeviceFactory::operator()(const deviceClassName &name) {
      return std::forward<uniqueDevice>(_traits[name]);
    }
    
    void DeviceFactory::initialize(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate) {
      _traits["Bulb"] = std::unique_ptr<Device>(new Bulb(name, portName, portRate));
//      _traits["Termo"] = std::unique_ptr<Device>(new TemperatureModule(name, portName, portRate));
    }
  }
}
