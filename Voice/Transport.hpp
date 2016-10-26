#include "Transport.h"

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
    
    Transport::Transport()
    :_curl(curl_easy_init()), _headers(nullptr) {
      checkConnection(_curl);
    }
    
    Transport::~Transport() {
      curl_free(_headers);
      curl_easy_cleanup(_curl);
    }
    
    bool Transport::connect() {
      if (!_curl) {
        _curl = curl_easy_init();
      }
      return checkConnection(_curl);
    }
    
    bool Transport::run() {
      if (!_curl) {
        return false;
      }
      optionsList();
      std::ifstream fileStream("./output.wav", std::ifstream::binary);
      fileStream.seekg (0, fileStream.end);
      int length = fileStream.tellg();
      fileStream.seekg (0, fileStream.beg);
      
      curl_easy_setopt(_curl, CURLOPT_READFUNCTION, &readRequestData);
      curl_easy_setopt(_curl, CURLOPT_POSTFIELDSIZE, length);
      curl_easy_setopt(_curl, CURLOPT_READDATA, &fileStream);
      std::stringstream contentStream;
      curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &writeResponseData);
      curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &contentStream);
      _code = curl_easy_perform(_curl);
      
      unsigned httpCode;
      curl_easy_getinfo(_curl, CURLINFO_HTTP_CODE, &httpCode);
      std::stringstream msg;
      msg << "Http code is " << httpCode;
      std::cout << contentStream.str();
      return true;
    }
    
    bool Transport::checkConnection(const socket *curl) {
      if (!curl) {
        printf("Connection is lost\nPlease, try again\n");
      }
      return static_cast<bool>(curl);
    }
    
    void Transport::optionsList() {
      curl_easy_setopt(_curl, CURLOPT_HEADER, boost::any<long>(map["CURLOPT_HEADER"]));
      curl_easy_setopt(_curl, CURLOPT_POST, 1);
      curl_easy_setopt(_curl, CURLOPT_VERBOSE, 1);
      curl_easy_setopt(_curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
      _headers = curl_slist_append(_headers, "Content-Type: audio/x-wav");
      boost::any str = "KeepAliveClient";
      curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, _headers);
      curl_easy_setopt(_curl, CURLOPT_USERAGENT, boost::any_cast<std::string>(str).c_str());
      curl_easy_setopt(_curl, CURLOPT_URL, "asr.yandex.net/asr_xml?key=d9def809-0bc4-4954-b0c9-6d544d787581&uuid=0CD748B1936933CEAA07FD7813B05877&topic=queries&lang=ru-RU");
    }
  }
}