#ifndef SENTENCE_H
#define SENTENCE_H

#pragma once

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

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
    phrase getSentence();
    friend bool operator==(const Sentence &lhs, const Sentence &rhs);
    
    private params:
    phrase _phrase;
  };
  
  bool operator==(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase == rhs._phrase;
  }
}

#endif // SENTENCE_H
