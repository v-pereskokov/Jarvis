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
    
    struct States {
      using state = std::shared_ptr<State>;
      
      friend class Device;
      
      public methods:
      States();
      States(const States &copy) = default;
      States(States &&copy) = default;
      States & operator=(const States &copy) = default;
      States & operator=(States &&copy) = default;
      ~States() = default;
      
      void on(Device *device);
      void off(Device *device);
      void setCurrentState(state newState);
      state getCurrentState() const;
      state getPreviouslyState() const;
      
      protected params:
      state _current;
      state _previously;
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
      
      public methods:
      Device(const name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
      virtual ~Device() = default;
      
      virtual void on() = 0;
      virtual void off() = 0;
      virtual void execute(const command &command) = 0;
      
      name getName() const;
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
