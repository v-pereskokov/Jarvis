#ifndef VOICE_H
#define VOICE_H

#pragma once

#include <string>
#include "../src/Sentence.cpp"
#include "../src/Command.cpp"

namespace Jarvis {
#define methods
#define params
  
  class Voice final {
    using map = connection::Map;
    using path = std::string;
    using name = std::string;
    
    public methods:
    Voice(const path &path, const name &name);
    ~Voice() = default;
    Voice(const Voice &copy) = default;
    Voice(Voice &&copy) = default;
    Voice & operator=(const Voice &copy) = default;
    bool say();
    void setSentence(const Sentence &sentence);
    Sentence getSentence() const;
    
    private methods:
    Voice() = delete;
    bool execute();
    bool findCommand(const connection::Map &waves, const Sentence &sentence);
    
    private params:
    name _name;
    map _waves;
    Sentence _sentence;
  };
}

#endif // VOICE_H
