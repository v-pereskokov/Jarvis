#pragma once

#ifndef MEDIATORCREATOR_H
#define MEDIATORCREATOR_H

#include <string>
#include <map>
#include <utility>
#include "Mediator.hpp"
#include "YandexSpeechKitMediator.hpp"

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
    
    class MediatorCreator {
      using mediator = Mediator::Mediator;
      using mediator_ptr = std::shared_ptr<mediator>;
      using mediatorName = std::string;
      using mediators = std::map<mediatorName, mediator_ptr>;
      
      public methods:
      MediatorCreator();
      ~MediatorCreator() = default;
      MediatorCreator(const MediatorCreator &copy) = default;
      MediatorCreator(MediatorCreator &&copy) = default;
      MediatorCreator & operator=(const MediatorCreator &copy) = default;
      MediatorCreator & operator=(MediatorCreator &&copy) = default;
      mediator_ptr operator()(const mediatorName &name) const;
      
      private methods:
      void initialization();
      
      private params:
      mediators _mediators;
    };
  }
}

#endif // MEDIATORCREATOR_H
