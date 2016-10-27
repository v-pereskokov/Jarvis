#ifndef TRANSPORT_H
#define TRANSPORT_H

#pragma once

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
    
    std::size_t writeResponseData(char *ptr, size_t size, size_t nmemb, void *userdata);
    std::size_t readRequestData(char *ptr, size_t size, size_t nmemb, void *userdata);
    
    class Transport final {
      using socket = CURL;
      using codeInfo = CURLcode;
      using headerList = curl_slist;
      using jPath = std::string;
      using response = std::stringstream;
      using responseString = std::string;
      using file = std::ifstream;
      
      struct OptionsList {
        friend class Transport;
        
        using yandexOption = std::string;
        using jList = std::map<std::string, std::string>;
        using url = std::string;
        using option = std::string;
        using optionValue = std::string;
        using optionList = std::map<std::string, std::string>;
        using yandexOptions = std::vector<yandexOption>;
        
        public methods:
        explicit OptionsList(const jPath &path);
        optionValue getOption(const option &option);
        
        private methods:
        OptionsList() = delete;
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
      
      using property = OptionsList;
      
      public methods:
      explicit Transport(const jPath &path);
      ~Transport();
      bool connect();
      bool isConnect();
      bool send();
      responseString recv() const;
      
      private methods:
      Transport() = delete;
      Transport(const Transport &copy) = delete;
      Transport & operator=(const Transport &copy) = delete;
      bool checkConnection(const socket *curl);
      void setOptions();
      
      private params:
      socket *_curl;
      property _properties;
      headerList *_headers;
      response _response;
    };
  }
}

#endif // TRANSPORT_H
