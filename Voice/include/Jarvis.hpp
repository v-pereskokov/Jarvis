#ifndef JARVIS_H
#define JARVIS_H

#pragma once

#include <string>
#include <boost/utility.hpp>
#include "../src/Transport.cpp"
#include "../src/Sentence.cpp"
#include "../src/Command.cpp"
#include "../src/SerialPort.cpp"
#include "../src/SpeechKit.cpp"
#include "../src/Voice.cpp"

namespace Jarvis {
#define methods
#define params
#define structs
  
  class Jarvis : boost::noncopyable {
    using map = Jarvis::connection::Map;
    using SerialPort = Jarvis::Arduino::Connection::SerialPort;
    using stringVoice = std::string;
    
    public methods:
    static Jarvis& instance();
    static void say();
    static stringVoice sendToYandexSpeechKit();
    static void sendToSerialPort(SerialPort &serial, const std::string &command);
    
    private methods:
    Jarvis() = default;
    ~Jarvis() = default;
    Jarvis(const Jarvis &copy) = delete;
    Jarvis(Jarvis &&copy) = delete;
    Jarvis & operator=(const Jarvis &copy) = delete;
    Jarvis & operator=(Jarvis &&copy) = delete;
    friend struct JarvisDestroyer;
    
    private structs:
    struct JarvisDestroyer : boost::noncopyable {
      public methods:
      JarvisDestroyer() = default;
      ~JarvisDestroyer();
      void initialize(Jarvis *jarvis, Voice *voice);
      
      private methods:
      JarvisDestroyer(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer(JarvisDestroyer &&copy) = delete;
      JarvisDestroyer & operator=(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer & operator=(JarvisDestroyer &&copy) = delete;
      
      private params:
      Jarvis *_jarvis;
      Voice *_voice;
    };
    
    private params:
    static Jarvis *_jarvis;
    static Voice *_voice;
    static JarvisDestroyer _destroyer;
  };
    
}

#endif // JARVIS_H
