#ifndef DEVICES_H
#define DEVICES_H

#pragma once

#include <string>
#include <map>
#include <memory>
#include "Bulb.hpp"
//#include "TemperatureModule.hpp"

namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define structs
    
    class DeviceFactory final {
      using deviceClassName = std::string;
      using uniqueDevice = std::unique_ptr<Device>;
      using devicesTraits = std::map<deviceClassName, uniqueDevice>;
      using type = std::string;
      
      public methods:
      DeviceFactory(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      
      ~DeviceFactory() = default;
      DeviceFactory(const DeviceFactory &copy) = default;
      DeviceFactory(DeviceFactory &&copy) = default;
      DeviceFactory& operator=(const DeviceFactory &copy) = default;
      DeviceFactory& operator=(DeviceFactory &&copy) = default;
      
      uniqueDevice operator()(const deviceClassName &name);
      
      private methods:
      DeviceFactory() = delete;
      void initialize(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate);
      
      private params:
      devicesTraits _traits;
    };
  }
}

#endif // DEVICES_H
