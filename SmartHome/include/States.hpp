#ifndef STATES_H
#define STATES_H

#pragma once

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Arduino
   * \brief Для работы с Arduino
   */
  namespace Arduino {
#define methods
#define params
#define structs
    
    template <class Arduino>
    class State {
      public methods:
      State() = default;
      State(const State &copy) = default;
      State(State &&copy) = default;
      State & operator=(const State &copy) = default;
      State & operator=(State &&copy) = default;
      virtual ~State() = default;
      
      virtual void on(Arduino *arduino) = 0;
      
      virtual void off(Arduino *arduino) = 0;
    };
    
    template <class Arduino>
    class On : public State<Arduino> {
      public methods:
      On() = default;
      ~On() = default;
      
      void off(Arduino *arduino) override;
    }
    
    template <class Arduino>
    class Off : public State<Arduino> {
      public methods:
      Off() = default;
      ~Off() = default;
      
      void on(Arduino *arduino) override;
    }
  }
}

#endif // STATES_H
