#ifndef JSONPARSER_H
#define JSONPARSER_H

#pragma once

#include <fstream>
#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>

namespace Jarvis {
#define methods
#define params
  
  using boost::property_tree::ptree;
  
  /*
   * struct Json:
   * "key_1" : {"key_2" : "data"}
   * !add load file
   */
  
  class JsonParser final {
    using jTree = ptree;
    using jFile = std::fstream;
    using jPath = std::string;
    using jKey = std::string;
    using jData = std::string;
    using jMap = std::map<jKey, jData>;
    
    public methods:
    explicit JsonParser(const jPath &path);
    JsonParser(const JsonParser &copy) = default;
    JsonParser & operator=(const JsonParser &copy) = default;
    jMap parse();
    
    private methods:
    JsonParser() = delete;
    
    private params:
    jFile _file;
    jTree _tree;
  };
}

#endif // JSONPARSER_H
