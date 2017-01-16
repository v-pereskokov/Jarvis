#include "../include/SerialPort.hpp"

namespace Jarvis {
  namespace Connection {
    SerialPort::SerialPort(const portName &name, const portRate rate)
    :_service(), _info(new PortInformation(name, rate)), _port(_service) {
      connection();
    }
    
    SerialPort::~SerialPort() {
      delete _info;
    }
    
    void SerialPort::write(const message &message) {
      boost::asio::write(_port, buffer(message.c_str(), message.size()));
    }
    
    SerialPort::message SerialPort::read() {
      byte byte;
      message message;
      while (true) {
        boost::asio::read(_port, buffer(&byte, 1));
        switch (byte) {
          case '\r':
            break;
          case '\n':
            return message;
          default:
            message += byte;
        }
      }
    }
    
    void SerialPort::setRate(port &port, const portRate rate) {
      port.set_option(serial_port_base::baud_rate(rate));
    }
    
    void SerialPort::connection() {
      if (!_info->_isOpen) {
        _port.open(_info->_name);
        setRate(_port, _info->_rate);
        _info->_isOpen = true;
      }
    }
    
    void SerialPort::disconnection() {
      if (_info->_isOpen) {
        _port.close();
      }
    }
    
    SerialPort::PortInformation::PortInformation(const portName &name, const portRate rate)
    :_name(name), _rate(rate) {}
  }
}
