#ifndef VOICE_H
#define VOICE_H

#pragma once

#include <string>
#include "../Source/Sentence.cpp"
#include "../Source/Command.cpp"

namespace Jarvis {
#define methods
#define params
    
    class Voice final {
      using map = connection::Map;
      using path = std::string;
      using name = std::string;
      
      public methods:
      Voice(const path &path, const name &name, const Sentence &sentence);
      ~Voice() = default;
      bool say();
      void setSentence(const Sentence &sentence);
      Sentence getSentence() const;
      
      private methods:
      Voice() = delete;
      Voice(const Voice &copy) = delete;
      Voice(Voice &&copy) = delete;
      Voice & operator=(const Voice &copy) = delete;
      bool execute();
      bool findCommand(const connection::Map &waves, const Sentence &sentence);
      
      private params:
      map _waves;
      Sentence _sentence;
      name _name;
    };
}

#endif // VOICE_H
