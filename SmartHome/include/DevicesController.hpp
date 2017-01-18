#pragma once

#ifndef DEVICESCONTROLLER_H
#define DEVICESCONTROLLER_H

#include <chrono>
#include <thread>
#include "Devices/Devices.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Connection
   * \brief Для подключения к Arduino
   */
  namespace Connection {
#define methods
#define enums
    
    class DevicesController {
      public methods:
      static void action(Device *device, const TypeOfAction &type);
      public enums:
      enum class TypeOfAction { on, off }
    };
  }
}

#endif // DEVICESCONTROLLER_H
