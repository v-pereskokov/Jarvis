#pragma once

#include "../include/MediatorCreator.hpp"

namespace Jarvis {
  namespace Mediator {
    MediatorCreator::MediatorCreator() {
      initialization();
    }
    
    MediatorCreator::mediator_ptr MediatorCreator::operator()(const mediatorName &name) const {
      return _mediators[name];
    }
    
    void MediatorCreator::initialization() {
      _mediators["SpeechKit"] = std::make_shared<Mediator::YandexSpeechKitMediator>();
    }
  }
}
