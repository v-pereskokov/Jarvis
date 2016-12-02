#ifndef SPEECHKIT_H
#define SPEECHKIT_H

#pragma once

#include "../src/Transport.cpp"

namespace Jarvis {
  namespace connection {
#define methods
#define params
#define structs
    
    class SpeechKit : public Transport {
      public methods:
      SpeechKit(const Transport::jPath &path, const Transport::OptionsList::yandexOptions yandexOptions);
      ~SpeechKit() = default;
      bool send() override;
      
      protected methods:
      void setOptions() override;
      
      private methods:
      SpeechKit() = delete;
      SpeechKit(const SpeechKit &copy) = delete;
      SpeechKit & operator=(const SpeechKit &copy) = delete;
    };
  }
}

#endif // SPEECHKIT_H
