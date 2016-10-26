#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <curl/curl.h>
#include <boost/any.hpp>
#include "JsonParser.h"

namespace Jarvis {
  namespace connection {
#define public_methods
#define private_methods
#define params
    
    std::size_t writeResponseData(char *ptr, size_t size, size_t nmemb, void *userdata);
    
    std::size_t readRequestData(char *ptr, size_t size, size_t nmemb, void *userdata);
    
    class Transport final {
      using socket = CURL;
      using codeInfo = CURLcode;
      using headerList = curl_slist;
      
      class OptionList;
      
      public public_methods:
      Transport();
      
      ~Transport();
      
      bool connect();
      
      bool run();
      
      private private_methods:
      Transport(const Transport &copy) = delete;
      
      Transport & operator=(const Transport &copy) = delete;
      
      bool checkConnection(const socket *curl);
      
      void optionsList();
      
      private params:
      socket *_curl;
      codeInfo _code;
      headerList *_headers;
      
    };
    
    struct OptionList final {
      public public_methods:
      
      private private_methods:
      
      protected params:
      std::map<std::string, boost::any> _options;
    };
    
  }
}

#endif // TRANSPORT_H
