#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <fstream>
#include <string>
#include <map>
#include <boost/any.hpp>
#include <boost/property_tree/ptree.hpp>

namespace Jarvis {
  
#define public_methods
#define private_methods
#define params
  
  using boost::property_tree::ptree;
  using boost::property_tree::read_json;
  using boost::property_tree::write_json;
  using jTree = ptree;
  using jFile = std::fstream;
  using jPath = std::string;
  using jKey = std::string;
  using jData = std::string;
  
  class JsonParser final {
    public public_methods:
//    JsonParser(const jFile &file)
//    :_file(file) {}
    
    JsonParser(const jPath &path);
    
    JsonParser(const JsonParser &copy) = default;
    
    JsonParser & operator=(const JsonParser &copy) = default;
    
    std::map<jKey, jData> parse();
    
    private params:
    jFile _file;
    jTree _tree;
  };
}

#endif // JSONPARSER_H
