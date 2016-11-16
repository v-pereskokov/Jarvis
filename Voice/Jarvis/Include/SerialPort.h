#ifndef SERIALPORT_H
#define SERIALPORT_H

#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>

namespace Jarvis {
  namespace Arduino {
    namespace Connection {
#define methods
#define params
      
      using namespace boost::asio;
      
      class SerialPort final {
        using serviceIO = io_service;
        using port = serial_port;
        using portName = std::string;
        using portRate = size_t;
        using byte = char;
        using message = std::string;
        
      public methods:
        SerialPort(const portName &name, const portRate rate);
        ~SerialPort() = default;
        void write(const message &message);
        message read();
        
      private methods:
        SerialPort(const SerialPort &copy) = delete;
        SerialPort(const SerialPort &&copy) = delete;
        SerialPort& operator=(const SerialPort &copy) = delete;
        void setRate(port &port, const portRate rate);
        
      private params:
        serviceIO _service;
        port _port;
      };
    }
  }
}

#endif // SERIALPORT_H
