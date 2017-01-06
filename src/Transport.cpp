#include <sstream>
#include "../include/Transport.hpp"

namespace Jarvis {
  namespace connection {
    size_t writeResponseData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata) {
      std::stringstream *stream = static_cast<std::stringstream *>(pUserdata);
      size_t writeSize = size * count;
      stream->write(pChar, writeSize);
      return writeSize;
    }
    
    size_t readRequestData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata) {
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
    
    Transport::Transport(const jPath &path, const OptionsList::Options options)
    :_curl(curl_easy_init()), _properties(path, options), _headers(nullptr) {
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
    
    Transport::OptionsList::OptionsList(const jPath& path, const Options options)
    :_options(options) {
      Parser::jObject json(path);
      fillList(parsingTree(json.jsonParse()));
    }
    
    Transport::OptionsList::optionValue Transport::OptionsList::getOption(const Transport::OptionsList::option &option) {
      return _optList[option];
    }
    
    void Transport::OptionsList::fillList(const jList &list) {
      url url = list.at("url");
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (jProperty->first != "url" && !findOption(jProperty->first)) {
          _optList.insert({jProperty->first, jProperty->second.data()});
        }
      }
      url = makeUrl(list, url);
      _optList.insert({"url", url});
    }
    
    Transport::OptionsList::url Transport::OptionsList::makeUrl(const jList &list, url &url) {
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (findOption(jProperty->first)) {
          url.insert(url.find(jProperty->first + "=") + (jProperty->first).size() + 1, jProperty->second.data());
        }
      }
      return url;
    }
    
    bool Transport::OptionsList::findOption(const Option &option) {
      auto findOption = std::find(_options.begin(), _options.end(), option);
      return findOption != _options.end();
    }
  }
}
