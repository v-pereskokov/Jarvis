#pragma once

#include "../include/Arduino.hpp"

namespace Jarvis {
  namespace Arduino {
    Arduino::Ardiuno(const name &name, const SerialPort::portName &portName, const SerialPort::portRate rate)
    :_name(name), _port(portName, rate) {}
    
    void Arduino::send(const signal &signal) {
      _port.write(signal);
    }
    
    Arduino::signal Arduino::read() {
      _port.read();
    }
  }
}
