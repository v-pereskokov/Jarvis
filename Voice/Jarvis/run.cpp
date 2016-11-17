#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <sstream>
#include <cctype>
#include "Transport.hpp"
#include "Sentence.hpp"
#include "Command.hpp"
#include "SerialPort.hpp"

using boost::property_tree::ptree;

Jarvis::Arduino::Connection::SerialPort serial("/dev/cu.usbmodem1411", 9600);

void voiceJarvis(const std::string &phrase) {
  std::string audioSamplePath = "afplay Samples/" + phrase + ".wav";
  system(audioSamplePath.c_str());
}

void doing(const std::string &command) {
  if (command == "3") {
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  }
  serial.write(command);
}

std::map<std::string, std::string> handleQuery() {
  Jarvis::connection::Transport opt("Configs/speechkit.json");
  opt.send();
  std::string response(opt.recv());
  response.erase(response.begin(), response.begin() + response.find("<"));
  std::stringstream stream;
  stream << response;
  std::map <std::string, std::string> map = Jarvis::connection::parsingTree(Jarvis::xmlParse(stream));
  return map;
}

std::pair<bool, std::string> search (std::string &word, std::map<std::string, std::pair<std::string, std::string>> &cmds) {
  for (auto it = cmds.begin(); it != cmds.end(); ++it) {
    std::string map_words = it->first;
    std::istringstream stream(map_words);
    std::string map_word;
    while (stream >> map_word) {
      std::transform(word.begin(), word.end(), word.begin(), tolower);
      if (word == map_word) {
        return {true, map_words};
      }
    }
  }
  return {false, "error"};
}

std::pair<std::string, std::string> check(std::string &command, std::map<std::string, std::pair<std::string, std::string>> &cmds) {
  std::istringstream stream(command);
  std::string word;
  while (stream >> word) {
    auto result = search(word, cmds);
    if (result.first) {
      return cmds.at(result.second);
    }
  }
  return {"4", "Error"};
}

int run() {
  std::thread voice(voiceJarvis, "Welcome");
  system("Scripts/hello.sh");
  voice.join();
  std::string exit = "nothing";
  while (exit != "stop") {
    system("python Scripts/record.py Samples/output.wav");
    std::map<std::string, std::string> map = handleQuery();
    std::map<std::string, std::pair<std::string, std::string>> cmds{
      {"включи свет", {"1", "LedOn"}}, {"выключи свет", {"0", "LedOff"}}, {"моргание", {"2", "Blink"}}, {"зажигай", {"3", "VoiceHighwayToHell"}}};
    std::string command = map["variant"];
    auto isDoing = check(command, cmds);
    if (command == "Умри" || command == "Успокойся") {
      break;
    } else if (atoi(isDoing.first.c_str()) < 4) {
      std::thread voice(voiceJarvis, std::ref(isDoing.second));
      std::thread work(doing, std::ref(isDoing.first));
      voice.join();
      work.join();
      if (atoi(isDoing.first.c_str()) == 3) {
        system("afplay Samples/HighwayToHell.mp3");
      }
    } else {
      printf("%s\n", command.c_str());
      system("afplay Samples/Error.wav");
    }
    std::cout << "Есть еще пожелания?\n" << "\"stop\" - для завершения\n";
    system("afplay Samples/SomethingElse.wav");
    std::getline(std::cin, exit);
  }
  system("Scripts/goodbye.sh");
  system("afplay Samples/Goodbye.wav");
  
  //  Jarvis::Commands::Command::execute(Jarvis::Commands::CommandType::python, "Scripts/record.py", {"tests.wav"});
  
  //  try {
  //
  //    Jarvis::Arduino::Connection::SerialPort serial("/dev/cu.usbmodem1411", 9600);
  //    std::string s;
  //    while (s != "stop") {
  //      std::getline(std::cin, s);
  //      serial.write(s);
  //
  //      //      cout<<serial.readLine()<<endl;
  //    }
  //
  //  } catch(boost::system::system_error& e)
  //  {
  //  std::cout<<"Error: "<<e.what()<<std::endl;
  //  return 1;
  //  }
  return 0;
}
