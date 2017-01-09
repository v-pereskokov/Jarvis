#include "../include/Arduino/ArduinoCommands.hpp"

namespace Jarvis {
  namespace Arduino {
    ArduinoCommands::ArduinoCommands(const Arduino &arduino)
    :_arduino(arduino) {}
    
    void ArduinoCommands::command(const command &command) {
      _arduino.send(checkState(command));
    }
    
    ArduinoStates::~ArduinoStates() {
      delete _current;
      delete _previous;
    }
    
    ArduinoCommands::ArduinoStates::ArduinoState ArduinoCommands::getCurrentState() const {
      return _states._current;
    }
    
    ArduinoCommands::ArduinoStates::ArduinoState ArduinoCommands::getPreviousState() const {
      return _states._previous;
    }
    
    void ArduinoCommands::setCurrentState(const ArduinoStates::ArduinoState &state) {
      setPreviousState(_states._current);
      _states._current = state
    }
    
    void ArduinoCommands::setPreviousState(const ArduinoStates::ArduinoState &state) {
      _states._previous = state;
    }
    
    ArduinoCommands::command ArduinoCommands::checkState(const command &command) {
      // Handle commands
    }
  }
}
