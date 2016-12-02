#include "../include/Voice.hpp"
#include "Transport.cpp"

namespace Jarvis {
    Voice::Voice(const path &path, const name &name, const Sentence &sentence)
    :_waves(connection::parsingTree((connection::jObject(path)).jsonParse())), _sentence(sentence), _name(name) {
    }
    
    void Voice::setSentence(const Sentence &sentence) {
      if (_sentence == sentence) {
        return;
      }
      _sentence = sentence;
    }
    
    Sentence Voice::getSentence() const {
      return _sentence;
    }
    
    bool Voice::say() {
      return execute();
    }
    
    bool Voice::execute() {
      if (!findCommand(_waves, _sentence)) {
        Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::music, "", {"samples/error.wav"});
        return false;
      }
      Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::music, "", {_waves.at(_sentence.getSentence())
      });
      return true;
    }
    
    bool Voice::findCommand(const map &waves, const Sentence &sentence) {
      for (auto it = waves.begin(); it != waves.end(); ++it) {
        if ((it->first).find(sentence.getSentence()) != std::string::npos) {
          return true;
        }
      }
      return false;
    }
}
