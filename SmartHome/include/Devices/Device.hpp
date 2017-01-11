#ifndef DEVICE_H
#define DEVICE_H

#pragma once

#include <string>
#include "../SerialPort.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace Devices {
#define methods
#define params
#define usings
#define enums
    
    class Device;
    struct States;
    
    class State {
      protected usings:
      using command = std::string;
      
      friend class Device;
      friend struct States;
      
      public methods:
      State() = default;
      State(const State &copy) = default;
      State(State &&copy) = default;
      State & operator=(const State &copy) = default;
      State & operator=(State &&copy) = default;
      virtual ~State() = default;
      
      virtual void on(Device *device);
      virtual void off(Device *device);
    };
    
    class On : public State {
      friend class Device;
      public methods:
      On() = default;
      ~On() = default;
      
      void off(Device *device) override;
    };
    
    class Off : public State {
      friend class Device;
      public methods:
      Off() = default;
      ~Off() = default;
      
      void on(Device *device) override;
    };
    
    struct States {
      using state = State*;
      
      friend class Device;
      friend class Bulb;
      
      protected enums:
      enum class StateName {off, on};
      
      public methods:
      States() = default;
      States(const States &copy) = default;
      States(States &&copy) = default;
      States & operator=(const States &copy) = default;
      States & operator=(States &&copy) = default;
      ~States() = default;
      
      void on(Device *device);
      void off(Device *device);
      void setCurrentState(state newState);
      StateName getStateName() const;
      
      protected params:
      state _current{new Off()};
      state _previously{new Off()};
      StateName _sName{StateName::off};
    };
    
    class Device {
      protected usings:
      /*!
       * \using Connection::SerialPort port
       * \brief Определяет тип для порта, по которому будут отправляться сигналы
       */
      using port = Connection::SerialPort;
      
      /*!
       * \using std::string name
       * \brief Определяет тип для имени платы
       */
      using name = std::string;
      
      /*!
       * \using std::string signal
       * \brief Определяет тип для отправляемого сигнала
       */
      using command = std::string;
      using state = States;
      
      friend class DeviceFactory;
      friend struct States;
      friend class State;
      friend class On;
      friend class Off;
      
      public methods:
      Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      virtual ~Device() = default;
      
      virtual void on() = 0;
      virtual void off() = 0;
      virtual void manual(const command &command) = 0;
      virtual void previously() = 0;

      name getName() const;
      
      protected methods:
      virtual void execute(const command &command) = 0;
      
      state getState() const;
      
      private methods:
      Device() = delete;
      Device(const Device &copy) = delete;
      Device(Device &&copy) = delete;
      Device& operator=(const Device &copy) = delete;
      Device& operator=(Device &&copy) = delete;
      
      protected params:
      name _name; /*!< имя устройства*/
      port _port; /*!< порт подключения*/
      state _state; /*!< состояние устройства*/
    };
  }
}

#endif // DEVICE_H
