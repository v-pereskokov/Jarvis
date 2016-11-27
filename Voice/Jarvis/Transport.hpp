#pragma once

#include "Include/Transport.h"
#include "OptionsList.hpp"
#include "Parser.hpp"

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
    
    Map parsingTree(const Jarvis::Parser::Tree &tree) {
      Map result;
      for (auto it_first = tree.begin(); it_first != tree.end(); ++it_first) {
        auto object = it_first->second;
        for (auto it_second = object.begin(); it_second != object.end(); ++it_second) {
          result.insert({it_second->first, it_second->second.data()});
        }
      }
      return result;
    }
    
    Transport::Transport(const jPath &path, const OptionsList::yandexOptions yandexOptions)
    :_curl(curl_easy_init()), _properties(path, yandexOptions), _headers(nullptr) {
      checkConnection(_curl);
    }
    
    Transport::~Transport() {
      curl_free(_headers);
      curl_easy_cleanup(_curl);
    }
    
    Transport::responseString Transport::recv() const {
      return _response.str();
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
    
    bool Transport::checkConnection(const socket *curl) {
      if (!curl) {
        printf("Connection is lost\nPlease, try again\n");
      }
      return static_cast<bool>(curl);
    }
  }
}
