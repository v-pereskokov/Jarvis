#include "../include/Devices/Bulb.hpp"

namespace Jarvis {
  namespace Devices {
    Bulb::Bulb(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    void Bulb::on() {
      execute("a"); // on
    }
    
    void Bulb::off() {
      execute("x"); // off
    }
    
    void Bulb::manual(const Device::command &command) {
      execute(command);
    }
    
    Device::name Bulb::getName() const {
      return _name;
    }
    
    void Bulb::execute(const Device::command &command) {
      _port.write(makeRequest(command));
    }
    
    Device::command Bulb::makeRequest(const Device::command &command) const {
      return getName() + "" + command; // name + "_" + cmd
    }
  }
}
