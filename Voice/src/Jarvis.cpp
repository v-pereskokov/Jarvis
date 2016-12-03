#pragma once

#include "../include/Jarvis.hpp"

namespace Jarvis {
  Jarvis * Jarvis::_jarvis = nullptr;
  Jarvis::JarvisDestroyer Jarvis::_destroyer;
  
  Jarvis::JarvisDestroyer::~JarvisDestroyer() {
    delete _jarvis;
  }
  
  void Jarvis::JarvisDestroyer::initialize(Jarvis *jarvis) {
    _jarvis = jarvis;
  }
  
  Jarvis& Jarvis::instance() {
    if(!_jarvis) {
      Voice voice("../conf/voiceJarvis.json", "Jarvis");
      _jarvis = new Jarvis(voice);
      _destroyer.initialize(_jarvis);
    }
    return *_jarvis;
  }
  
  void Jarvis::say(Voice &voice, const sayPhrase &phrase) {
    voice.setSentence(phrase);
    voice.say();
  }
  
  void Jarvis::toArduino() {
    using mapCommands = std::map<std::string, std::pair<std::string, std::string>>;
    try {
      Commands::Command::execute(Commands::CommandType::shell, "./scripts/hello.sh", {});
      Commands::Command::execute(Commands::CommandType::music, "", { "./samples/Welcome.wav" });
      while (true) {
        Commands::Command::execute(Commands::CommandType::python, "./scripts/record.py", { "./samples/output.wav" });
        mapCommands cmds{
          {"включи свет", {"a", "LedOn"}}, {"выключи свет", {"x", "LedOff"}}, {"подмигни", {"2", "Blink"}}, {"зажигай", {"3", "VoiceHighwayToHell"}}};
        stringVoice command = sendToYandexSpeechKit();
        printf("string: %s\n", command.c_str());
        Commands::Command::execute(Commands::CommandType::music, "", { "./samples/SomethingElse.wav" });
        char c;
        scanf("%c", &c);
      }
      Commands::Command::execute(Commands::CommandType::shell, "./scripts/goodbye.sh", {});
      Commands::Command::execute(Commands::CommandType::music, "", { "./samples/Goodbye.wav" });
    } catch(boost::system::system_error& e) {
      printf("Error: %s\n", e.what());
    } catch (...) {
      printf("Unknown error\n");
    }
  }
  
  Jarvis::Jarvis(Voice &voice)
  :_voice(voice) {}
  
  Jarvis::stringVoice Jarvis::sendToYandexSpeechKit() {
    return getMapFromYandexSpeechKit("./conf/speechkit.json")["variant"];
  }
  
  void Jarvis::sendToSerialPort(SerialPort &serial, const std::string &command) {
    if (command == "3") {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    serial.write(command);
  }
  
  Jarvis::map Jarvis::getMapFromYandexSpeechKit(const pathToConfigs &path) {
    using namespace std;
    using keys = vector<std::string>;
    using responseString = string;
    
    connection::SpeechKit toYandex(path, keys{"key", "uuid", "topic", "lang"});
    toYandex.send();
    responseString response(toYandex.recv());
    response.erase(response.begin(), response.begin() + response.find("<"));
    stringstream stream;
    stream << response;
    return map(connection::parsingTree(xmlParse(stream)));
  }
}
