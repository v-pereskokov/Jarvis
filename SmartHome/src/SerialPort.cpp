#include "../include/SerialPort.hpp"

namespace Jarvis {
  namespace Arduino {
    namespace Connection {
      SerialPort::SerialPort(const portName &name, const portRate rate)
      :_service(), _port(_service, name) {
        setRate(_port, rate);
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
    }
  }
}
