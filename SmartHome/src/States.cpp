#include "../include/States.hpp"

namespace Jarvis {
  namespace Arduino {
    void On::off(Arduino *arduino) {
      arduino->setPreviousState(arduino->getCurrentState());
      arduino->setCurrentState(new Off<Arduino>());
      delete this;
    }
    
    void Off::on(Arduino *arduino) {
      arduino->setPreviousState(arduino->getCurrentState());
      arduino->setCurrentState(new On<Arduino>());
      delete this;
    }

  }
}
