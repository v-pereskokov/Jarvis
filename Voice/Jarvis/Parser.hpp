#pragma once 

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "Include/Parser.h"

namespace Jarvis {
  using boost::property_tree::read_json;
  using boost::property_tree::write_json;
  
  Parser::Parser(const Path &path)
  :_target(path) {}
  
  void Parser::loadTarget(const Path &path) {
    _target = path;
  }
  
  Parser::Map Parser::jsonParse() {
    Map result;
    read_json(_target, _tree);
    return fillMap(result, _tree);
  }
  
  Parser::Map Parser::xmlParse() {
    Map result;
    read_xml(_target, _tree);
    return fillMap(result, _tree);
  }
  
  Parser::Map Parser::fillMap(Map &result, const Tree &tree) {
    for (auto it_first = tree.begin(); it_first != tree.end(); ++it_first) {
      auto object = it_first->second;
      for (auto it_second = object.begin(); it_second != object.end(); ++it_second) {
        result.insert({it_second->first, it_second->second.data()});
      }
    }
    return result;
  }
}
