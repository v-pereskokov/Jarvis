#pragma once

#include "Include/SpeechKit.h"

namespace Jarvis {
  namespace connection {
    SpeechKit::SpeechKit(const Transport::jPath &path, const Transport::OptionsList::yandexOptions yandexOptions)
    :Transport(path, yandexOptions) {
      setOptions();
    }
    
    bool SpeechKit::send() {
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
    
    void SpeechKit::setOptions() {
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
