#ifndef SENTENCE_H
#define SENTENCE_H

#pragma once

#include <string>

namespace Jarvis {
  
#define methods
#define params
  
  class Sentence {
    using phrase = std::string;
    
    public methods:
    Sentence(const phrase &phrase);
    Sentence(const Sentence &copy);
    Sentence(Sentence &&copy);
    Sentence & operator=(const Sentence &copy);
    ~Sentence() = default;
    void setSentence(const Sentence &sentence);
    void setSentence(const phrase &phrase);
    phrase getSentence() const;
    friend bool operator==(const Sentence &lhs, const Sentence &rhs);
    friend bool operator!=(const Sentence &lhs, const Sentence &rhs);
    friend bool operator>(const Sentence &lhs, const Sentence &rhs);
    friend bool operator<(const Sentence &lhs, const Sentence &rhs);
    friend bool operator>=(const Sentence &lhs, const Sentence &rhs);
    friend bool operator<=(const Sentence &lhs, const Sentence &rhs);
    
    private params:
    phrase _phrase;
  };
  
  bool operator==(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase == rhs._phrase;
  }
  
  bool operator!=(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase != rhs._phrase;
  }
  
  bool operator>(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase > rhs._phrase;
  }
  
  bool operator<(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase < rhs._phrase;
  }
  
  bool operator>=(const Sentence &lhs, const Sentence &rhs) {
    return !(lhs < rhs);
  }
  
  bool operator<=(const Sentence &lhs, const Sentence &rhs) {
    return !(lhs > rhs);
  }
  
}

#endif // SENTENCE_H
