#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include "Transport.hpp"

using boost::property_tree::ptree;

void voiceJarvis(const std::string &phrase) {
  std::string audioSamplePath = "afplay Samples/" + phrase + ".wav";
  system(audioSamplePath.c_str());
}

void doing(const std::string &command) {
  std::string arduinoScript = "Scripts/./startArduino.sh " + command;
  system(arduinoScript.c_str());
}

int run() {
  system("Scripts/./hello.sh");
  char exit = 'y';
  while (exit != 'n') {
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
      {"Выключи свет", "LedOff"}, {"Моргание", "Blink"}
                                            };
    std::string command = map["variant"];
    if (cmds.find(command) != cmds.end()) {
      std::thread work(doing, std::ref(cmds[command]));
      std::thread voice(voiceJarvis, std::ref(cmds[command]));
      work.join();
      voice.join();
    } else {
      system("afplay Samples/Error.wav");
    }
    system("afplay Samples/SomethingElse.wav");
    printf("Еще есть пожелания? y/n\n");
    scanf("%c", &exit);
  }
  system("afplay Samples/Goodbye.wav");
  system("Scripts/./goodbye.sh");
  return 0;
}
