#pragma once

#include "../include/ArduinoCommands.hpp"

namespace Jarvis {
  namespace Arduino {
    ArduinoCommands::ArduinoCommands(const Arduino &arduino)
    :_arduino(arduino) {}
    
    void ArduinoCommands::command(const State &state) {
      _arduino.send(_states[state]);
    }
    
    void ArduinoCommands::command(const command &command) {
      _arduino.send(command);
    }
  }
}
