#pragma once

#include "../include/Transport.hpp"
#include "OptionsList.cpp"
#include "Parser.cpp"

namespace Jarvis {
  namespace connection {
    std::size_t writeResponseData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata) {
      std::stringstream *stream = static_cast<std::stringstream *>(pUserdata);
      size_t writeSize = size * count;
      stream->write(pChar, writeSize);
      return writeSize;
    }
    
    std::size_t readRequestData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata) {
      std::ifstream *stream = static_cast<std::ifstream *>(pUserdata);
      size_t readSize = size * count;
      stream->read(pChar, readSize);
      size_t result = stream->gcount();
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
    
    bool Transport::isConnect() const {
      return checkConnection(_curl);
    }
    
    bool Transport::checkConnection(const socket *curl) const {
      if (!curl) {
        printf("Connection is lost\nPlease, try again\n");
      }
      return static_cast<bool>(curl);
    }
  }
}
