#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include "CompilePB/basic.pb.h"
#include "CompilePB/voiceproxy.pb.h"
#include "notation.h"

using boost::asio::ip::tcp;

using namespace VoiceProxyProtobuf;


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

decltype(auto) read(boost::shared_ptr<tcp::socket> socket)
{
    boost::asio::streambuf response;
    boost::asio::read_until(*socket, response, "\r\n");
    
    std::istream response_stream(&response);
    std::string status_message;
    std::getline(response_stream, status_message);
    return status_message;
}

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service ios;
        tcp::resolver resolver(ios);
        tcp::resolver::query query("asr.yandex.net", "http");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        
        boost::shared_ptr<tcp::socket> socket(new tcp::socket(ios));
        
        boost::asio::connect(*socket, endpoint_iterator);
        
        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "GET /asr_partial HTTP/1.1\r\nUser-Agent: KeepAliveClient\r\nHost: asr.yandex.net:80\r\nUpgrade: dictation\r\n\r\n";
        
        boost::asio::write(*socket, request);
        
        std::string status_message = read(socket);
        
        std::cout << "\nStatus message: \n" << status_message << std::endl;
        
        
        boost::shared_ptr<ConnectionRequest> CR(new ConnectionRequest);
        std::vector<std::string> settings;
        
        setting_init(settings, argc, argv);
        setup(settings, CR);
        CR->PrintDebugString();
        char message[200];
        CR->SerializeToArray(&message, 200);
        
        std::string hex_size = toNotation(200, 16);
        
        boost::asio::streambuf request_cr;
        std::ostream request_stream_cr(&request_cr);
        request_stream_cr << hex_size;
        request_stream_cr << "\r\n";
        request_stream_cr << message;

        boost::asio::write(*socket, request_cr);
        
        std::string response = read(socket);
        
        boost::shared_ptr<BasicProtobuf::ConnectionResponse> CResp(new BasicProtobuf::ConnectionResponse);
        
        CResp->ParseFromString(response);
        CResp->PrintDebugString();
        
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    return 0;
}