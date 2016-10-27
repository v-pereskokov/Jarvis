#ifndef OPTIONSLIST_H
#define OPTIONSLIST_H

#include <algorithm>
#include "Include/Transport.h"
#include "JsonParser.hpp"

namespace Jarvis {
  namespace connection {
    using jObject = JsonParser;
    
    OptionsList::OptionsList(const jPath& path) {
      jObject json(path);
      fillList(json.parse());
    }
    
    void OptionsList::fillList(const jList &list) {
      url url = list.at("url");
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (jProperty->first != "url" && !findYandexOption(jProperty->first)) {
          _options.insert({jProperty->first, jProperty->second.data()});
        }
      }
      url = makeUrl(list, url);
      _options.insert({"url", url});
    }
    
    OptionsList::url OptionsList::makeUrl(const jList &list, url &url) {
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (findYandexOption(jProperty->first)) {
          url.insert(url.find(jProperty->first + "=") + (jProperty->first).size() + 1, jProperty->second.data());
        }
      }
      return url;
    }
    
    bool OptionsList::findYandexOption(const yandexOption &option) {
      auto findOption = std::find(_yaOpts.begin(), _yaOpts.end(), option);
      return findOption != _yaOpts.end();
    }
  }
}

#endif // OPTIONSLIST_H
