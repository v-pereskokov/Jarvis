#include "../include/Jarvis.hpp"
#include <iostream>

namespace Jarvis {
  Jarvis *Jarvis::_jarvis = nullptr;
  Jarvis *Jarvis::_jarvis = &Jarvis::Jarvis::instance();
  
  Jarvis::stringVoice Jarvis::getStringVoice() {
//    std::cout << "TOPTOPTOPTOPTOP\n";
//    _voice->record();
//    std::cout << "TOPTOPTOPTOPTOP\n";
//    std::cout << "here_____sent: " << _voice->voiceRecognition() << std::endl;
    _voice->setSentence("включить");
    std::cout << _voice->getSentence() << std::endl;
    return _voice->getSentence();
  }
  
  Jarvis::JarvisDestroyer::~JarvisDestroyer() {
    delete _jarvis;
    delete _voice;
  }
  
  void Jarvis::JarvisDestroyer::initialize(Jarvis *jarvis, Voice *voice) {
    _jarvis = jarvis;
    _voice = voice;
  }
  
  std::pair<Jarvis*, Voice*> Jarvis::instance() {
    if (!_jarvis) {
      _jarvis = new Jarvis;
      _voice = new Voice("Jarvis");
      _destroyer.initialize(_jarvis, _voice);
    }
    return {_jarvis, _voice};
  }
  
  Jarvis *Jarvis::_jarvis = Jarvis::instance().first;
  Jarvis::JarvisDestroyer Jarvis::_destroyer;
  Voice *Jarvis::_voice = Jarvis::instance().second;
}
