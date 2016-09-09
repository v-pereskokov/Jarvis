//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <assert.h>
//#include <boost/type_erasure/any.hpp>
//#include <boost/type_erasure/operators.hpp>
//#include <boost/mpl/vector.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/asio.hpp>
//#include <curl/curl.h>
//#include "ConnectionRequest/ConnectionRequest_function.h"
//#include "ConnectionResponse/ConnectionResponse.pb.h"
//#include "notation.h"
//
//using namespace Jarvis;
//using namespace boost::asio::ip;
//using namespace boost::asio;
//
//// vector<any>
//typedef std::vector<type_e::any<boost::mpl::vector<
//type_e::copy_constructible<>,
//type_e::destructible<>,
//type_e::ostreamable<> > > > boost_any_vector;
//
//std::size_t write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata)
//{
//    std::stringstream* s = static_cast<std::stringstream *>(userdata);
//    size_t n = size *nmemb;
//    s->write(ptr, n);
//    return n;
//}
//
//std::size_t read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata)
//{
//    std::ifstream *f = static_cast<std::ifstream *>(userdata);
//    size_t n = size *nmemb;
//    f->read(ptr, n);
//    size_t result = f->gcount();
//    return result;
//}
//
//// ./build <FILENAME> <UUID> <APIKEY> <APPNAME> <DEVICE> <LANG> <FORMAT>
//int main(int argc, char* argv[])
//{
////    boost::shared_ptr<ConnectionRequest> CR(new ConnectionRequest);
////    std::vector<std::string> settings;
////
////    setting_init(settings, argc, argv);
////    setup(settings, CR);
////    CR->PrintDebugString();
////    char message[200];
////    CR->SerializeToArray(&message, 200);
////
////    std::string hex_size = toNotation(200, 16);
////    const std::string end = "\r\n";
////    std::string request = hex_size + end + message;
////    std::cout << request << std::endl;
////        CURL *curl = nullptr;
////        curl_global_init(CURL_GLOBAL_DEFAULT);
////        curl = curl_easy_init();
////        if (curl) {
////            curl_easy_setopt(curl, CURLOPT_HEADER, 1);
////            curl_easy_setopt(curl, CURLOPT_URL, "asr.yandex.net");
////            curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP);
////            curl_easy_setopt(curl, CURLOPT_PORT, 80);
////    #ifdef SKIP_PEER_VERIFICATION
////            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
////    #endif
////    #ifdef SKIP_HOSTNAME_VERIFICATION
////            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
////    #endif
////            curl_slist *headers = NULL;
////            headers = curl_slist_append(headers, "Content-Type: audio/x-wav");
////            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
////            curl_easy_setopt(curl, CURLOPT_URL, "asr.yandex.net/?User-Agent=KeepAliveClient&Hosе=asr.yandex.net:80&Upgrade=dictation");
////            CURLcode res = curl_easy_perform(curl);
////            if (res != CURLE_OK)
////                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
////            curl_easy_cleanup(curl);
////        }
////        curl_global_cleanup();
////
////
////    std::string start = "GET /asr_partial HTTP/1.1\r\nUser-Agent: KeepAliveClient\r\nHost: asr.yandex.net:80\r\nUpgrade: dictation\r\n\r\n";
//    io_service service;
//    tcp::resolver resolver(service);
//    tcp::resolver::iterator iter = resolver.resolve(tcp::resolver::query("www.yahoo.com","80"));
//    tcp::socket sock(service);
//    connect(sock, iter);
//
//    return 0;
//}
//
////#include <iostream>
////#include <string>
////#include <boost/asio.hpp>
////typedef boost::asio::ip::tcp tcp;
////
////int main()
////{
////    std::string host = "den-x.comule.com";
////    try{
////        boost::asio::io_service io;
////        tcp::resolver resolver(io);
////        tcp::socket sock(io);
////        boost::system::error_code err;
////        boost::asio::streambuf buf;
////        std::ostream reqStream(&buf);
////        std::istream respStream(&buf);
////        tcp::resolver::query q(host, "http");
////        tcp::resolver::iterator it = resolver.resolve(q, err), itEnd;
////        if (err)
////        {
////            std::cerr<<"resolve() failed:\n"<<err.message()<<"\n";
////            return __LINE__;
////        }
////        err = boost::asio::error::host_not_found;
////        while (err && it != itEnd)
////        {
////            sock.close();
////            sock.connect(*it++, err);
////        }
////        if (err)
////        {
////            std::cerr << "connect() failed\n";
////            return __LINE__;
////        }
////        std::string body("user=tester");
////        reqStream << "POST /act.php HTTP/1.1\r\n"
////        << "Host: " << host << "\r\n"
////        << "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; ru; rv:1.9.2.25) Gecko/20111212 Firefox/3.6.25 sputnik 2.5.1.2\r\n"
////        << "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
////        << "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n"
////        << "Accept-Encoding: gzip,deflate\r\n"
////        << "Accept-Charset: windows-1251,utf-8;q=0.7,*;q=0.7\r\n"
////        << "Keep-Alive: 115\r\n"
////        << "Connection: keep-alive\r\n"
////        << "Referer: http://den-x.comule.com\r\n"
////        << "Content-Type: application/x-www-form-urlencoded\r\n"
////        << "Content-Length: " << body.size() << "\r\n\r\n"
////        << body;
////        boost::asio::write(sock, buf);
////        boost::asio::read(sock, buf, err);
////        if(err != boost::asio::error::eof) std::cerr << "read() failed\n";
////        std::cout << &buf << std::endl;
////        sock.shutdown(tcp::socket::shutdown_both);
////        sock.close();
////    }
////    catch (const std::exception& e)
////    {
////        std::cerr << "Exception: " << e.what() << std::endl;
////    }
////    return 0;
////}
//
////#include <iostream>
////#include <string>
////#include <curl/curl.h>
////
////using namespace std;
////
////int writer(char *data, size_t size, size_t nmemb, string *buffer);
////string curl_httpget(const string &url);
////
////int main(int argc, char *argv[])
////{
////    cout << curl_httpget("GET /asr_partial HTTP/1.1\r\nUser-Agent: KeepAliveClient\r\nHost: asr.yandex.net:80\r\nUpgrade: dictation\r\n\r\n") << endl;
////}
////
////string curl_httpget(const string &url)
////{
////    string buffer;
////
////    CURL *curl;
////    CURLcode result;
////
////    curl = curl_easy_init();
////
////    if (curl)
////    {
////        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()  );
////        curl_easy_setopt(curl, CURLOPT_HEADER, 0);
////        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
////        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
////
////        result = curl_easy_perform(curl);//http get performed
////
////        curl_easy_cleanup(curl);//must cleanup
////
////        //error codes: http://curl.haxx.se/libcurl/c/libcurl-errors.html
////        if (result == CURLE_OK)
////            return buffer;
////        //curl_easy_strerror was added in libcurl 7.12.0
////        cerr << "error: " << result << " " << curl_easy_strerror(result) <<endl;
////        return "";
////    }
////
////    cerr << "error: could not initalize curl" << endl;
////    return "";
////}
////
////int writer(char *data, size_t size, size_t nmemb, string *buffer)
////{
////    int result = 0;
////    if (buffer != NULL)
////    {
////        buffer->append(data, size * nmemb);
////        result = size * nmemb;
////    }
////    return result;
////}

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include "ConnectionRequest/ConnectionRequest.pb.h"
#include "ConnectionResponse/ConnectionResponse.pb.h"
#include "notation.h"

using boost::asio::ip::tcp;

using namespace Jarvis;

// Init settings
bool setting_init(std::vector<std::string> &settings, const int argc, char *argv[])
{
    if (argc == 8) {
        for (std::size_t i = 2; i < argc; ++i)
            settings.push_back(static_cast<std::string>(argv[i]));
        return true;
    }
    return false;
}

// Setup ConnectionRequest
bool setup(const std::vector<std::string> &settings, boost::shared_ptr<ConnectionRequest> CR)
{
    if (settings.size() == 6) {
        CR->set_protocolversion(1);
        CR->set_speechkitversion("");
        CR->set_servicename("asr.yandex.net");
        CR->set_uuid(settings[0]);
        CR->set_apikey(settings[1]);
        CR->set_applicationname(settings[2]);
        CR->set_device(settings[3]);
        CR->set_coords("0, 0");
        CR->set_topic("queries");
        CR->set_lang(settings[4]);
        CR->set_format(settings[5]);
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    try
    {
        
        boost::asio::io_service io_service;
        
        // Get a list of endpoints corresponding to the server name.
        tcp::resolver resolver(io_service);
        tcp::resolver::query query("asr.yandex.net", "http");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        
        // Try each endpoint until we successfully establish a connection.
        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);
        
        // Form the request. We specify the "Connection: close" header so that the
        // server will close the socket after transmitting the response. This will
        // allow us to treat all data up until the EOF as the content.
        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "GET /asr_partial HTTP/1.1\r\nUser-Agent: KeepAliveClient\r\nHost: asr.yandex.net:80\r\nUpgrade: dictation\r\n\r\n";
        
        // Send the request.
                boost::asio::write(socket, request);
        socket.send(boost::asio::buffer(request));
        
        // Read the response status line. The response streambuf will automatically
        // grow to accommodate the entire line. The growth may be limited by passing
        // a maximum size to the streambuf constructor.
                boost::asio::streambuf response;
                boost::asio::read_until(socket, response, "\r\n");
        
        // Check that response is OK.
                std::istream response_stream(&response);
        //        std::string http_version;
        //        response_stream >> http_version;
        //        unsigned int status_code;
        //        response_stream >> status_code;
        std::string status_message;
        socket.receive(boost::asio::buffer(status_message));
                std::getline(response_stream, status_message);
        std::cout << "\nStatus message: \n" << status_message << std::endl;
        // Read the response headers, which are terminated by a blank line.
        //        boost::asio::read_until(socket, response, "\r\n\r\n");
        
        // Process the response headers.
                std::string header;
                while (std::getline(response_stream, header) && header != "\r")
                    std::cout << header << "\n";
                std::cout << "\n";
//         Write whatever content we already have to output.
                if (response.size() > 0)
                    std::cout << &response;
        
        boost::shared_ptr<ConnectionRequest> CR(new ConnectionRequest);
        std::vector<std::string> settings;
        
        setting_init(settings, argc, argv);
        setup(settings, CR);
        CR->PrintDebugString();
        char message[200];
        CR->SerializeToArray(&message, 200);
        
        std::string hex_size = toNotation(200, 16);
        const std::string end = "\r\n";
        
        boost::asio::streambuf request_;
        std::ostream request_stream_(&request_);
        request_stream_ << hex_size;
        request_stream_ << "\r\n";
        request_stream_ << message;
        std::cout << "Exception: " << "\n";
        boost::asio::write(socket, request_);
        std::cout << "Exception: " << "\n";
        boost::asio::streambuf response_;
        std::cout << "Exception: " << "\n";
        boost::system::error_code err_code;
        std::size_t n = 200;
        boost::asio::read(socket, response_, boost::asio::transfer_at_least(32));
        
        std::istream response_stream_(&response_);
        //        std::string http_version;
        //        response_stream >> http_version;
        //        unsigned int status_code;
        //        response_stream >> status_code;
        std::string status_message_;
        std::getline(response_stream_, status_message_);
        
        boost::shared_ptr<ConnectionResponse> CResp(new ConnectionResponse);
        CResp->ParseFromString(status_message_);
        CResp->PrintDebugString();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    return 0;
}