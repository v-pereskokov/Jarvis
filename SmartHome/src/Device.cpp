#include "../include/Devices/Device.hpp"

namespace Jarvis {
  namespace Devices {
    void State::off(Device *device) {}
    
    void State::on(Device *device) {}
    
    void On::off(Device *device) {
      device->getState().setCurrentState(new Off());
      delete this;
    }
    
    void Off::on(Device *device) {
      device->getState().setCurrentState(new On());
      delete this;
    }
    
    void States::on(Device *device) {
      device->execute("a"); // on
    }
    
    void States::off(Device *device) {
      device->execute("x"); // off
    }
    
    void States::setCurrentState(state newState) {
      _previously = _current;
      _current = newState;
    }
    
    States::StateName States::getStateName() const {
      return _sName;
    }
    
    Device::Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :_name(name), _port(portName, portRate) {}
    
    Device::name Device::getName() const {
      return _name;
    }
    
    Device::state Device::getState() const {
      return _state;
    }
  }
}
