#ifndef JARVIS_H
#define JARVIS_H

#pragma once

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <boost/utility.hpp>
#include "../src/Command.cpp"
#include "../src/SerialPort.cpp"
#include "../src/SpeechKit.cpp"
#include "../src/Voice.cpp"

namespace Jarvis {
#define methods
#define params
#define structs
  
  class Jarvis : boost::noncopyable {
    using map = connection::Map;
    using SerialPort = Arduino::Connection::SerialPort;
    using stringVoice = std::string;
    using pathToConfigs = std::string;
    using sayPhrase = std::string;
    
    public methods:
    static Jarvis& instance();
    static void say(Voice &voice, const sayPhrase &phrase);
    static void toArduino();
//    static void toArduino(SerialPort &serial, SerialPort &serial1);
    
    private methods:
    Jarvis() = default;
    Jarvis(Voice &voice);
    ~Jarvis() = default;
    Jarvis(const Jarvis &copy) = delete;
    Jarvis(Jarvis &&copy) = delete;
    Jarvis & operator=(const Jarvis &copy) = delete;
    Jarvis & operator=(Jarvis &&copy) = delete;
    friend struct JarvisDestroyer;
    static stringVoice sendToYandexSpeechKit();
    static void sendToSerialPort(SerialPort &serial, const std::string &command);
    static map getMapFromYandexSpeechKit(const pathToConfigs &path);
    
    private structs:
    struct JarvisDestroyer : boost::noncopyable {
      public methods:
      JarvisDestroyer() = default;
      ~JarvisDestroyer();
      void initialize(Jarvis *jarvis);
      
      private methods:
      JarvisDestroyer(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer(JarvisDestroyer &&copy) = delete;
      JarvisDestroyer & operator=(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer & operator=(JarvisDestroyer &&copy) = delete;
      
      private params:
      Jarvis *_jarvis;
    };
    
    private params:
    static Jarvis *_jarvis;
    static JarvisDestroyer _destroyer;
    Voice _voice;
  };
    
}

#endif // JARVIS_H
