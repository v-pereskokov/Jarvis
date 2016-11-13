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
    
    Sentence(const phrase &phrase);
    Sentence(const Sentence &copy);
    Sentence(Sentence &&copy);
  private:
    phrase _phrase;
  };
}

#endif // SENTENCE_H
