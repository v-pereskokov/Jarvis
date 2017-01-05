#include "../include/Jarvis.hpp"

namespace Jarvis {
  Jarvis * Jarvis::_jarvis = nullptr;
  Jarvis::JarvisDestroyer Jarvis::_destroyer;
  
  Jarvis::bitsFromSmartHome Jarvis::smartHome(const stringVoice& command) {
    return command;
  }
  
  Jarvis::JarvisDestroyer::~JarvisDestroyer() {
    delete _jarvis;
  }
  
  void Jarvis::JarvisDestroyer::initialize(Jarvis *jarvis) {
    _jarvis = jarvis;
  }
  
  Jarvis& Jarvis::instance() {
    if(!_jarvis) {
      Voice voice("../conf/voiceJarvis.json", "Jarvis");
      _jarvis = new Jarvis(voice);
      _destroyer.initialize(_jarvis);
    }
    return *_jarvis;
  }
  
  void Jarvis::say(Voice &voice, const sayPhrase &phrase) {
    voice.setSentence(phrase);
    voice.say();
  }
  
  Jarvis::Jarvis(Voice &voice)
  :_voice(voice) {}
}
