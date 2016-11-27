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
#include "../Parser.hpp"

namespace Jarvis {
  namespace connection {
#define methods
#define params
#define structs
#define usings
    
    using Key = std::string;
    using Data = std::string;
    using Map = std::map<Key, Data>;
    
    std::size_t writeResponseData(char *ptr, size_t size, size_t nmemb, void *userdata);
    std::size_t readRequestData(char *ptr, size_t size, size_t nmemb, void *userdata);
    Map parsingTree(const Jarvis::Parser::Tree &tree);
    
    class Transport {
      protected usings:
      using socket = CURL;
      using codeInfo = CURLcode;
      using headerList = curl_slist;
      using jPath = std::string;
      using response = std::stringstream;
      using responseString = std::string;
      using file = std::ifstream;
      
      public structs:
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
        explicit OptionsList(const jPath &path, const yandexOptions yandexOptions);
        optionValue getOption(const option &option);
        ~OptionsList() = default;
        
        private methods:
        OptionsList() = delete;
        OptionsList(const OptionsList &copy) = delete;
        OptionsList & operator=(const OptionsList &copy) = delete;
        void fillList(const jList &list);
        url makeUrl(const jList &list, url &url);
        bool findYandexOption(const yandexOption &option);
        
        protected params:
        optionList _optList;
        
        private params:
        yandexOptions _yandexOptions;
      };
      
      using property = OptionsList;
      
      public methods:
      explicit Transport(const jPath &path, const OptionsList::yandexOptions yandexOptions);
      virtual ~Transport();
      virtual bool send() = 0;
      responseString recv() const;
      bool connect();
      bool isConnect();
      
      protected methods:
      bool checkConnection(const socket *curl);
      virtual void setOptions() = 0;
      
      private methods:
      Transport() = delete;
      Transport(const Transport &copy) = delete;
      Transport & operator=(const Transport &copy) = delete;
      
      protected params:
      socket *_curl;
      property _properties;
      headerList *_headers;
      response _response;
    };
  }
}

#endif // TRANSPORT_H
