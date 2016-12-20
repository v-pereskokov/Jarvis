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
      initializeMediators(_mediators);
      _jarvis = new Jarvis(voice);
      _destroyer.initialize(_jarvis);
    }
    return *_jarvis;
  }
  
  void Jarvis::say(Voice &voice, const sayPhrase &phrase) {
    voice.setSentence(phrase);
    voice.say();
  }
  
  Jarvis::stringVoice Jarvis::toArduino() {
    using mapCommands = std::map<std::string, std::pair<std::string, std::string>>;
    Commands::Command::execute(Commands::CommandType::shell, "../scripts/hello.sh", {});
    Commands::Command::execute(Commands::CommandType::music, "", { "../samples/Welcome.wav" });
    Commands::Command::execute(Commands::CommandType::python, "../scripts/record.py", { "../samples/output.wav" });
    mapCommands cmds{
      {"включи свет", {"a", "LedOn"}}, {"выключи свет", {"x", "LedOff"}}, {"подмигни", {"2", "Blink"}}, {"зажигай", {"3", "VoiceHighwayToHell"}}};
//    stringVoice command = sendToYandexSpeechKit(); //fix
    Commands::Command::execute(Commands::CommandType::music, "", { "../samples/SomethingElse.wav" });
    Commands::Command::execute(Commands::CommandType::shell, "../scripts/goodbye.sh", {});
    Commands::Command::execute(Commands::CommandType::music, "", { "../samples/Goodbye.wav" });
//    return command;
    return "soon in your compukters";
  }
  
  Jarvis::Jarvis(Voice &voice)
  :_voice(voice) {}
  
  void Jarvis::sendToSerialPort(SerialPort &serial, const std::string &command) {
    if (command == "3") {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    serial.write(command);
  }
  
  void Jarvis::initializeMediators(mediators &mediators) {
    mediators["SpeechKit"] = std::make_shared<Mediator::YandexSpeechKitMediator>();
  }
  
  Jarvis::mediator_ptr Jarvis::getMediator(const mediatorName &name) {
    return _mediators[name];
  }
}
