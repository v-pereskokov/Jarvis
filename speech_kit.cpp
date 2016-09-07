#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <curl/curl.h>

std::size_t write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::stringstream* s = static_cast<std::stringstream *>(userdata);
    size_t n = size *nmemb;
    s->write(ptr, n);
    return n;
}

std::size_t read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::ifstream *f = static_cast<std::ifstream *>(userdata);
    size_t n = size *nmemb;
    f->read(ptr, n);
    size_t result = f->gcount();
    return result;
}

void easy_setport_init(CURL *curl)
{
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
}

void easy_setport_speech_kit(CURL *curl, const curl_slist *headers)
{
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Dalvik/1.2.0 (Linux; U; Android 2.2.2; LG-P990 Build/FRG83G");
    curl_easy_setopt(curl, CURLOPT_URL, "asr.yandex.net/asr_xml?key=d9def809-0bc4-4954-b0c9-6d544d787581&uuid=0CD748B1936933CEAA07FD7813B05877&topic=queries&lang=ru-RU");
}

void easy_curl_close(CURL *curl, curl_slist *headers)
{
    curl_free(headers);
    curl_easy_cleanup(curl);
}

void handling(const char *FILE_PATH)
{
    CURL *curl = NULL;
    curl = curl_easy_init();
    if (curl) {
        easy_setport_init(curl);
        curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: audio/x-wav");
        easy_setport_speech_kit(curl, headers);
        std::ifstream fileStream(FILE_PATH, std::ifstream::binary);
        fileStream.seekg (0, fileStream.end);
        std::size_t length = fileStream.tellg();
        fileStream.seekg (0, fileStream.beg);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, &read_request_data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, length);
        curl_easy_setopt(curl, CURLOPT_READDATA, &fileStream);
        std::stringstream contentStream;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_response_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentStream);
        CURLcode result = curl_easy_perform(curl);
        if (result == CURLE_OK)
            std::cout << contentStream.str();
        else
            std::cout << "Ошибка" << std::endl;
        easy_curl_close(curl, headers);
    }
}
