#include "../include/Parser.hpp"

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
  
  Parser::Tree jsonParse(Parser::stringTarget &stream) {
    Parser::Tree tree;
    read_json(stream, tree);
    return tree;
  }
  
  Parser::Tree xmlParse(Parser::stringTarget &stream) {
    Parser::Tree tree;
    read_xml(stream, tree);
    return tree;
  }
}
