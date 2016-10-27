#include <sstream>
#include <map>
#include <iostream>
#include "Jarvis/Transport.hpp"

int main() {
  Jarvis::JsonParser j("configuration.json");
  std::map <std::string, std::string> map;
  map = j.parse();
  for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  Jarvis::connection::OptionsList opt("configuration.json");
  return 0;
}