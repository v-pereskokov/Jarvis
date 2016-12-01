#include "../Include/Sentence.hpp"

namespace Jarvis {
  Sentence::Sentence(const phrase &phrase)
  : _phrase(phrase) {}
  
  Sentence::Sentence(const Sentence &copy)
  : _phrase(copy._phrase) {}
  
  Sentence::Sentence(Sentence &&copy) {
    _phrase = copy._phrase;
    copy._phrase = "";
  }
  
  Sentence & Sentence::operator=(const Sentence &copy) {
    if (this == &copy) {
      return *this;
    }
    _phrase = copy._phrase;
    return *this;
  }
  
  void Sentence::setSentence(const Sentence &sentence) {
    if (this == &sentence) {
      return;
    }
    _phrase = sentence._phrase;
  }
  
  void Sentence::setSentence(const phrase &phrase) {
    if (_phrase == phrase) {
      return;
    }
    _phrase = phrase;
  }
  
  Sentence::phrase Sentence::getSentence() {
    return _phrase;
  }
}
