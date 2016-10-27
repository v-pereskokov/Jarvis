#include "Include/Transport.h"
#include "OptionsList.hpp"
#include "JsonParser.hpp"

namespace Jarvis {
  namespace connection {
    std::size_t writeResponseData(char *ptr, size_t size, size_t nmemb, void *userdata) {
      std::stringstream *s = static_cast<std::stringstream *>(userdata);
      size_t n = size * nmemb;
      s->write(ptr, n);
      return n;
    }
    
    std::size_t readRequestData(char *ptr, size_t size, size_t nmemb, void *userdata) {
      std::ifstream* f = static_cast<std::ifstream *>(userdata);
      size_t n = size * nmemb;
      f->read(ptr, n);
      size_t result = f->gcount();
      return result;
    }
    
    Transport::Transport(const jPath &path)
    :_curl(curl_easy_init()), _properties(path), _headers(nullptr) {
      checkConnection(_curl);
      setOptions();
    }
    
    Transport::~Transport() {
      curl_free(_headers);
      curl_easy_cleanup(_curl);
    }
    
    bool Transport::connect() {
      if (!_curl) {
        _curl = curl_easy_init();
      }
      return checkConnection(_curl);
    }
    
    bool Transport::isConnect() {
      return checkConnection(_curl);
    }
    
    bool Transport::send() {
      if (!isConnect()) {
        return false;
      }
      file fileStream("./" + _properties.getOption("name"), std::ifstream::binary);
      fileStream.seekg (0, fileStream.end);
      int length = fileStream.tellg();
      fileStream.seekg (0, fileStream.beg);
      curl_easy_setopt(_curl, CURLOPT_READFUNCTION, &readRequestData);
      curl_easy_setopt(_curl, CURLOPT_POSTFIELDSIZE, length);
      curl_easy_setopt(_curl, CURLOPT_READDATA, &fileStream);
      curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &writeResponseData);
      curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_response);
      CURLcode _code = curl_easy_perform(_curl);
      return true;
    }
    
    Transport::responseString Transport::recv() const {
      return _response.str();
    }
    
    bool Transport::checkConnection(const socket *curl) {
      if (!curl) {
        printf("Connection is lost\nPlease, try again\n");
      }
      return static_cast<bool>(curl);
    }
    
    void Transport::setOptions() {
      curl_easy_setopt(_curl, CURLOPT_HEADER, std::stol(_properties.getOption("header")));
      curl_easy_setopt(_curl, CURLOPT_POST, std::stol(_properties.getOption("post")));
      curl_easy_setopt(_curl, CURLOPT_VERBOSE, std::stol(_properties.getOption("verbose")));
      curl_easy_setopt(_curl, CURLOPT_IPRESOLVE, std::stol(_properties.getOption("ipresolve")));
      std::string contentType = "Content-Type: " + _properties.getOption("content-type");
      _headers = curl_slist_append(_headers, contentType.c_str());
      curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, _headers);
      curl_easy_setopt(_curl, CURLOPT_USERAGENT, _properties.getOption("useragent").c_str());
      curl_easy_setopt(_curl, CURLOPT_URL, _properties.getOption("url").c_str());
    }
  }
}