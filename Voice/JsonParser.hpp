#include <sstream>
#include <boost/property_tree/json_parser.hpp>
#include "JsonParser.h"

namespace Jarvis {
  
  JsonParser::JsonParser(const jPath &path)
  :_file(path) {}
  
  std::map<std::string, std::string> JsonParser::parse() {
    std::map<std::string, std::string> result;
    std::stringstream stream;
    stream << _file.rdbuf();
    read_json(stream, _tree);
    for (auto it_first = _tree.begin(); it_first != _tree.end(); ++it_first) {
      auto object = it_first->second;
      for (auto it_second = object.begin(); it_second != object.end(); ++it_second) {
        result.insert({it_second->first, it_second->second.data()});
      }
    }
    return result;
  }
  
}
