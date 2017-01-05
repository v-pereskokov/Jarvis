#include "../include/Voice.hpp"

namespace Jarvis {
  Voice::Voice(const path &path, const name &name)
  :_name(name), _sentence("") {
    try {
      _waves = connection::parsingTree((Parser::jObject(path)).jsonParse());
    } catch(...) {
      Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::music, "", {"../samples/error.wav"});
      ;
    }
  }
  
  void Voice::setSentence(const sentence &sentence) {
    if (_sentence == sentence) {
      return;
    }
    _sentence = sentence;
  }
  
  Voice::sentence Voice::getSentence() const {
    return _sentence;
  }
  
  bool Voice::say() {
    return execute();
  }
  
  bool Voice::execute() {
    if (!findCommand(_waves, _sentence)) {
      Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::music, "", {"../samples/error.wav"});
      return false;
    }
    Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::music, "", {_waves.at(_sentence)});
    return true;
  }
  
  bool Voice::findCommand(const map &waves, const sentence &sentence) {
    for (auto it = waves.begin(); it != waves.end(); ++it) {
      if ((it->first).find(sentence) != std::string::npos) {
        return true;
      }
    }
    return false;
  }
}
