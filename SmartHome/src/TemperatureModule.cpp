#include "../include/Devices/TemperatureModule.hpp"

namespace Jarvis {
  namespace Devices {
    TemperatureModule::TemperatureModule(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Module(name, portName, portRate) {}
    
    TemperatureModule::temperature TemperatureModule::measure(const Module::scale &scale) {
      execute(scale);
      return 10.;
    }
    
    void TemperatureModule::execute(const Module::scale &scale) {
      // TODO
    }
  }
}
