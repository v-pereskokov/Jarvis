#include <sstream>
#include <map>
#include <iostream>
#include "Jarvis/Transport.hpp"
#include <boost/property_tree/ptree.hpp>

using boost::property_tree::ptree;

int main() {
//  system("python record.py output.wav");
  Jarvis::connection::Transport opt("configuration.json");
  opt.send();
  std::cout << "____" << std::endl;
  std::string response(opt.recv());
  response.erase(response.begin(), response.begin() + response.find("<"));
//  std::cout << response << std::endl;
  std::stringstream stream;
  stream << response;
  Jarvis::Parser j;
  std::map <std::string, std::string> map;
  map = Jarvis::xmlParse(stream);
  std::cout << typeid(map["variant"]).name() << std::endl;
  std::string cmd = "./" + map["variant"];
  system(cmd.c_str());
  return 0;
}
