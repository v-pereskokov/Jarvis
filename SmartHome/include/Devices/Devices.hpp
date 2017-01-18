#ifndef DEVICES_H
#define DEVICES_H

#pragma once

#include <string>
#include <map>
#include <memory>
#include <exception>
#include "Bulb.hpp"
#include "Teapot.hpp"
#include "Fan.hpp"
//#include "TemperatureModule.hpp"

namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define usings
  
    template <class Device, class... Args>
    class AbstractCreator {
      protected usings:
      using uniqueDevice = std::unique_ptr<Device>;
      
      public methods:
      AbstractCreator() = default;
      virtual ~AbstractCreator() = default;
      AbstractCreator(const AbstractCreator &copy) = default;
      AbstractCreator(AbstractCreator &&copy) = default;
      AbstractCreator& operator=(const AbstractCreator &copy) = default;
      AbstractCreator& operator=(AbstractCreator &&copy) = default;
      
      virtual uniqueDevice create(const Args&... args) const = 0;
    };
    
    template <class ConcreteDevice, class Device, class... Args>
    class Creator : public AbstractCreator<Device, Args...> {
      public methods:
      typename AbstractCreator<Device, Args...>::uniqueDevice create(const Args&... args) const override {
        return std::forward<typename AbstractCreator<Device, Args...>::uniqueDevice>
        (typename AbstractCreator<Device, Args...>::uniqueDevice(new ConcreteDevice(args...)));
      }
    };
    
    class DeviceFactory final {
      using deviceClassName = std::string;
      using uniqueDevice = std::unique_ptr<Device>;
      using sharedCreator = std::shared_ptr<AbstractCreator<Device, Device::name, Connection::SerialPort::portName, Connection::SerialPort::portRate>>;
      using devicesTraits = std::map<deviceClassName, sharedCreator>;
      using type = std::string;
      
      public methods:
      DeviceFactory();
      ~DeviceFactory() = default;
      DeviceFactory(const DeviceFactory &copy) = default;
      DeviceFactory(DeviceFactory &&copy) = default;
      DeviceFactory& operator=(const DeviceFactory &copy) = default;
      DeviceFactory& operator=(DeviceFactory &&copy) = default;
      
      uniqueDevice operator()(const deviceClassName &className, const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      
      private methods:
      void initialize();
      
      private params:
      devicesTraits _traits;
    };
  }
}

#endif // DEVICES_H
