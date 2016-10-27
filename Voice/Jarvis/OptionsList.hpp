#ifndef OPTIONSLIST_H
#define OPTIONSLIST_H

#include <algorithm>
#include "Include/Transport.h"
#include "JsonParser.hpp"

namespace Jarvis {
  namespace connection {
    using jObject = JsonParser;
    
    Transport::OptionsList::OptionsList(const jPath& path) {
      jObject json(path);
      fillList(json.parse());
    }
    
    Transport::OptionsList::optionValue Transport::OptionsList::getOption(const Transport::OptionsList::option &option) {
      return _optList[option];
    }
    
    void Transport::OptionsList::fillList(const jList &list) {
      url url = list.at("url");
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (jProperty->first != "url" && !findYandexOption(jProperty->first)) {
          _optList.insert({jProperty->first, jProperty->second.data()});
        }
      }
      url = makeUrl(list, url);
      _optList.insert({"url", url});
    }
    
    Transport::OptionsList::url Transport::OptionsList::makeUrl(const jList &list, url &url) {
      for (auto jIt = list.begin(); jIt != list.end(); ++jIt) {
        auto jProperty = jIt;
        if (findYandexOption(jProperty->first)) {
          url.insert(url.find(jProperty->first + "=") + (jProperty->first).size() + 1, jProperty->second.data());
        }
      }
      return url;
    }
    
    bool Transport::OptionsList::findYandexOption(const yandexOption &option) {
      auto findOption = std::find(_yaOpts.begin(), _yaOpts.end(), option);
      return findOption != _yaOpts.end();
    }
  }
}

#endif // OPTIONSLIST_H
