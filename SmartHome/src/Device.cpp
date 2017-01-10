#include "../include/Devices/Device.hpp"

namespace Jarvis {
  namespace Devices {
    void State::off(Device *device) {}
    
    void State::on(Device *device) {}
    
    void On::off(Device *device) {
      device->getState().setCurrentState(std::make_shared<State>(new Off()));
      delete this;
    }
    
    void Off::on(Device *device) {
      device->getState().setCurrentState(std::make_shared<State>(new On()));
      delete this;
    }
    
    States::States()
    :_current(new Off()), _previously(nullptr) {}
    
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
    
    States::state States::getCurrentState() const {
      return _current;
    }
    
    States::state States::getPreviouslyState() const {
      return _previously;
    }
    
    Device::Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :_name(name), _port(portName, portRate), _state() {}
    
    Device::name Device::getName() const {
      return _name;
    }
    
    Device::state Device::getState() const {
      return _state;
    }
  }
}
