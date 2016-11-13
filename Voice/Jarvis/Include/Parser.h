#ifndef PARSER_H
#define PARSER_H

#pragma once

#include <string>
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>

namespace Jarvis {
#define methods
#define params
  
  using boost::property_tree::ptree;
  
  /*
   * struct Json:
   * "key_1" : {"key_2" : "data"}
   */
  
  class Parser final {
    using Tree = ptree;
    using stringTarget = std::stringstream;
    using Path = std::string;
    using Key = std::string;
    using Data = std::string;
    using Map = std::map<Key, Data>;
    
    public methods:
    Parser() = default;
    explicit Parser(const Path &path);
    Parser(const Parser &copy) = default;
    Parser & operator=(const Parser &copy) = default;
    void loadTarget(const Path &path);
    Map jsonParse();
    friend Map jsonParse(stringTarget &stream);
    Map xmlParse();
    friend Map xmlParse(stringTarget &stream);
    
    private methods:
    static Map fillMap(Map &result, const Tree &tree);
    
    private params:
    Path _target;
    Tree _tree;
  };
  
  Parser::Map jsonParse(Parser::stringTarget &stream) {
    Parser::Map result;
    Parser::Tree tree;
    read_json(stream, tree);
    return Parser::fillMap(result, tree);
  }
  
  Parser::Map xmlParse(Parser::stringTarget &stream) {
    Parser::Map result;
    Parser::Tree tree;
    read_xml(stream, tree);
    return Parser::fillMap(result, tree);
  }
}

#endif // PARSER_H
