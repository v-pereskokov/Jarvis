#include "../include/Devices/Bulb.hpp"

namespace Jarvis {
  namespace Devices {
    Bulb::Bulb(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    void Bulb::on() {
      send("a"); // on
    }
    
    void Bulb::off() {
      send("x"); // off
    }
    
    void Bulb::manual(const command &command) {
      send(command);
    }
    
    Device::name Bulb::getName() const {
      return _name;
    }
    
    void Bulb::send(const command &command) {
      _port.write(makeRequest(command));
    }
    
    Device::signal Bulb::makeRequest(const command &command) const {
      return getName() + "" + command; // name + "_" + cmd
    }
  }
}
