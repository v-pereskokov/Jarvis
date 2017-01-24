#include "../include/Voice.hpp"
#include <iostream>

namespace Jarvis {
  Voice::Voice(const name &name)
  :_name(name), _sentence("") {}
  
  void Voice::setSentence(const sentence &sentence) {
    _sentence = sentence;
  }
  
  Voice::sentence Voice::getSentence() const {
    return _sentence;
  }
  
  void Voice::record() {
    Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::python, VoiceConfigurations::scriptRecord, {"/Users/vladislavpereskokov/Desktop/Projects/Jarvis/Jarvis/samples/output.wav"});
  }
  
  Voice::sentence Voice::voiceRecognition() {
    setSentence(sendVoiceToYandexSpeechKit(VoiceConfigurations::speechKitJson));
    return getSentence();
  }
  
  Voice::sentence Voice::recordAndGet() {
    record();
    return voiceRecognition();
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
  
  Voice::sentence Voice::sendVoiceToYandexSpeechKit(const path &path) {
    return getSentenceMapFromYandexSpeechKit(path)[VoiceConfigurations::resultSentenceKey];
  }
  
  Voice::map Voice::getSentenceMapFromYandexSpeechKit(const path &path) {
    using namespace std;
    using responseString = string;
    
    connection::SpeechKit toYandex(path, VoiceConfigurations::keys);
    toYandex.send();
    responseString response(toYandex.recv());
    response.erase(response.begin(), response.begin() + response.find("<"));
    stringstream stream;
    stream << response;
    return map(connection::parsingTree(xmlParse(stream)));
  }
}
