#include "../include/Jarvis.hpp"
#include <iostream>

namespace Jarvis {
  Voice Jarvis::_voice("Jarvis");
  Jarvis *Jarvis::_jarvis = &Jarvis::instance();
  Jarvis::JarvisDestroyer Jarvis::_destroyer;
  
  Jarvis::stringVoice Jarvis::getStringVoice() {
    return _voice.recordAndGet();
  }
  
  Jarvis::JarvisDestroyer::~JarvisDestroyer() {
    delete _jarvis;
  }
  
  void Jarvis::JarvisDestroyer::initialize(Jarvis *jarvis) {
    _jarvis = jarvis;
  }
  
  Jarvis& Jarvis::instance() {
    if (!_jarvis) {
      _jarvis = new Jarvis;
      _destroyer.initialize(_jarvis);
    }
    return *_jarvis;
  }
}
