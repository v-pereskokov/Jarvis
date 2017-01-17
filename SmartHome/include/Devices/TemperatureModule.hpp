#ifndef TEMPERATUREMODULE_H
#define TEMPERATUREMODULE_H

#pragma once

#include <string>
#include "Module.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
    
    class TemperatureModule : public Module {
      using temperature = double;
      
      public methods:
      TemperatureModule(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      ~TemperatureModule() = default;
      
      temperature measure(const Module::scale &scale);
      
      private methods:
      void execute(const Module::scale &scale) override;
    };
  }
}

#endif // TEMPERATUREMODULE_H
