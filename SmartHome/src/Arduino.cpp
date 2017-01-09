#include "../include/Arduino/Arduino.hpp"

namespace Jarvis {
  namespace Arduino {
    Arduino::Arduino(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate rate)
    :_name(name), _port(portName, rate) {}
    
    void Arduino::send(const signal &signal) {
      _port.write(signal);
    }
    
    Arduino::signal Arduino::read() {
      return _port.read();
    }
  }
}
