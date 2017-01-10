#ifndef STATES_H
#define STATES_H

#pragma once

#include <memory>
#include <string>

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
      public methods:
      On() = default;
      ~On() = default;
      
      void off(Device *device) override;
    };
    
    class Off : public State {
      public methods:
      Off() = default;
      ~Off() = default;
      
      void on(Device *device) override;
    };
    
    struct States {
      using state = std::shared_ptr<State>;
      
      friend class Device;
      friend class Bulb;
      
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
  }
}

#endif // STATES_H
