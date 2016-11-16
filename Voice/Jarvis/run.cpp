#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include "Transport.hpp"
#include "Sentence.hpp"
#include "Command.hpp"
#include "SerialPort.hpp"

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
  std::thread voice(voiceJarvis, "Welcome");
  system("Scripts/./hello.sh");
  voice.join();
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
                                            {"Включи свет", "LedOn"},{"Выключи свет", "LedOff"}, {"Моргание", "Blink"}};
    std::string command = map["variant"];
    if (cmds.find(command) != cmds.end()) {
      std::thread voice(voiceJarvis, std::ref(cmds[command]));
      std::thread work(doing, std::ref(cmds[command]));
      voice.join();
      work.join();
    } else if (command == "Зажигай") {
      std::thread voice(voiceJarvis, "VoiceHighwayToHell");
      std::thread work(doing, "HighwayToHell");
      voice.join();
      work.join();
      system("afplay Samples/HighwayToHell.mp3");
    } else if (command == "Умри" || command == "Успокойся") {
      break;
    } else {
      printf("%s\n", command.c_str());
      system("afplay Samples/Error.wav");
    }
    std::cout << "Есть еще пожелания?\n" << "\"stop\" - для завершения\n";
    system("afplay Samples/SomethingElse.wav");
    std::getline(std::cin, exit);
  }
  system("Scripts/./goodbye.sh");
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
