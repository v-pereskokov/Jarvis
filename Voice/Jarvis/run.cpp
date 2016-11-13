#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include "Transport.hpp"
#include "Sentence.hpp"
#include <boost/algorithm/string.hpp>

using boost::property_tree::ptree;

void voiceJarvis(const std::string &phrase, std::string &type = ".wav") {
  std::string audioSamplePath = "afplay Samples/" + phrase + type;
  system(audioSamplePath.c_str());
}

void doing(const std::string &command) {
  std::string arduinoScript = "Scripts/./startArduino.sh " + command;
  system(arduinoScript.c_str());
}

int run() {
  system("Scripts/./hello.sh");
  std::string exit = "nothing";
  while (exit != "stop") {
    system("python Scripts/record.py Samples/output.wav");
    Jarvis::connection::Transport opt("Configs/configuration.json");
    opt.send();
    std::string response(opt.recv());
    response.erase(response.begin(), response.begin() + response.find("<"));
    std::stringstream stream;
    stream << response;
    std::map <std::string, std::string> map = Jarvis::xmlParse(stream);
    std::map<std::string, std::string> cmds{
                                            {"Включи свет", "LedOn"},
      {"Выключи свет", "LedOff"}, {"Моргание", "Blink"}};
    std::string command = map["variant"];
    if (cmds.find(command) != cmds.end()) {
      std::thread voice(voiceJarvis, std::ref(cmds[command]));
      std::thread work(doing, std::ref(cmds[command]));
      voice.join();
      work.join();
    } else if (boost::algorithm::to_lower(map["variant"]) == boost::algorithm::to_lower("Зажигай")) {
      std::thread voice(voiceJarvis, std::ref("VoiceHighwayToHell"));
      std::thread work(doing, std::ref(HighwayToHell));
      voice.join();
      work.join();
    } else {
      system("afplay Samples/Error.wav");
    }
    printf("Еще есть пожелания?\n");
    system("afplay Samples/SomethingElse.wav");
    std::getline(std::cin, exit);
  }
  system("Scripts/./goodbye.sh");
  system("afplay Samples/Goodbye.wav");
  return 0;
}
