#pragma once

#include <sstream>
#include <boost/property_tree/json_parser.hpp>
#include "Include/JsonParser.h"

namespace Jarvis {
  using boost::property_tree::read_json;
  using boost::property_tree::write_json;
  using jStream = std::stringstream;
  
  JsonParser::JsonParser(const jPath &path)
  :_file(path) {}
  
  JsonParser::jMap JsonParser::parse() {
    jMap result;
    jStream stream;
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
