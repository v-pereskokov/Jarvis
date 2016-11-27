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
  
  Parser::Tree Parser::jsonParse() {
    read_json(_target, _tree);
    return _tree;
  }
  
  Parser::Tree Parser::xmlParse() {
    read_xml(_target, _tree);
    return _tree;
  }
}
