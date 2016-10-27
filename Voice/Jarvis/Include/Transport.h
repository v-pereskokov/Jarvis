#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <curl/curl.h>
#include <boost/any.hpp>

namespace Jarvis {
  namespace connection {
    
#define methods
#define params
    
    using jPath = std::string;
    
    std::size_t writeResponseData(char *ptr, size_t size, size_t nmemb, void *userdata);
    std::size_t readRequestData(char *ptr, size_t size, size_t nmemb, void *userdata);
    
    struct OptionsList final {
      using yandexOption = std::string;
      using jList = std::map<std::string, std::string>;
      using url = std::string;
      using optionList = std::map<std::string, std::string>;
      using yandexOptions = std::vector<yandexOption>;
      
      public methods:
      explicit OptionsList(const jPath& path);
      
      private methods:
      OptionsList(const OptionsList &copy) = delete;
      OptionsList & operator=(const OptionsList &copy) = delete;
      url makeUrl(const jList &list, url &url);
      void fillList(const jList &list);
      bool findYandexOption(const yandexOption &option);
      
      protected params:
      optionList _optList;
      
      private params:
      yandexOptions _yaOpts{"key", "uuid", "topic", "lang"};
    };
    
    class Transport final {
      struct OptionsList;
      
      using socket = CURL;
      using codeInfo = CURLcode;
      using headerList = curl_slist;
      using property = OptionsList;
      using request = boost::any;
      using fullRequest = std::vector<request>;
      
      public methods:
      explicit Transport(const jPath &path);
      ~Transport();
      bool connect();
      bool isConnect() const;
//      bool send();
      
      private methods:
      Transport() = delete;
      Transport(const Transport &copy) = delete;
      Transport & operator=(const Transport &copy) = delete;
      bool checkConnection(const socket *curl);
      
      private params:
      socket *_curl;
      property _properties;
      headerList *_headers;
      
    };
  }
}

#endif // TRANSPORT_H
