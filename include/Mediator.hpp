#pragma once

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <boost/utility.hpp>

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Mediator
   * \brief namespace для классов посредников
   */
  namespace Mediator {
#define methods
#define params
#define structs
    
    class Mediator : boost::noncopyable {
      public methods:
      Mediator() = default;
      virtual ~Mediator() = default;
      
      virtual void execute() = 0;
      
      private methods:
      Mediator(const Mediator &copy) = delete;
      Mediator(Mediator &&copy) = delete;
      Mediator & operator=(const Mediator &copy) = delete;
      Mediator & operator=(Mediator &&copy) = delete;
    };
  }
}

#endif // MEDIATOR_H
