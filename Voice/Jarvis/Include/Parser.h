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
#define usings
  using boost::property_tree::ptree;
  
  class Parser final {
    public usings:
    using Tree = ptree;
    using stringTarget = std::stringstream;
    using Path = std::string;
    
    public methods:
    Parser() = default;
    explicit Parser(const Path &path);
    Parser(const Parser &copy) = default;
    Parser & operator=(const Parser &copy) = default;
    void loadTarget(const Path &path);
    Tree jsonParse();
    friend Tree jsonParse(stringTarget &stream);
    Tree xmlParse();
    friend Tree xmlParse(stringTarget &stream);
    
    private params:
    Path _target;
    Tree _tree;
  };
  
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

#endif // PARSER_H
