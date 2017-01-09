#include "../include/Arduino/Commands.hpp"

namespace Jarvis {
  namespace Arduino {
    Commands::Commands(const ArduinoCommands *arduino)
    :_arduino(arduino) {}
    
    CommandOff::CommandOff(const ArduinoCommands *arduino)
    :Commands(arduino) {}
    
    void execute(const ArduinoCommands::command &command = "") {
      _arduino->command(State::off);
    }
    
    CommandOn::CommandOn(const ArduinoCommands *arduino)
    :Commands(arduino) {}
    
    void execute(const ArduinoCommands::command &command = "") {
      _arduino->command(State::on);
    }
    
    CommandOn::CommandOn(const ArduinoCommands *arduino)
    :Commands(arduino) {}
    
    void execute(const ArduinoCommands::command &command = "") {
      _arduino->command(command);
    }
    
  }
}
