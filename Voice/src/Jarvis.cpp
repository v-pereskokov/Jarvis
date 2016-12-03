#pragma once

#include "../include/Jarvis.hpp"

namespace Jarvis {
  Jarvis * Jarvis::_jarvis = nullptr;
  Jarvis::JarvisDestroyer Jarvis::_destroyer;
  
  Jarvis::JarvisDestroyer::~JarvisDestroyer() {
    delete _jarvis;
    delete _voice;
  }
  
  void Jarvis::JarvisDestroyer::initialize(Jarvis *jarvis, Voice *voice) {
    _jarvis = jarvis;
    _voice = voice
  }
  
  Jarvis& Jarvis::instance() {
    if(!_jarvis && !_voice) {
      _jarvis = new Jarvis();
      _voice = new Voice("../conf/voiceJarvis.json", "Jarvis");
      _destroyer.initialize(_jarvis, _voice);
    }
    return *_jarvis;
  }
}
