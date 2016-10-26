//#include <iostream>
//#include <ostream>
//#include <string>
//#include <boost/asio.hpp>
//#include <boost/shared_ptr.hpp>
//#include "ConnectionRequest/ConnectionRequest.pb.h"
//#include "ConnectionResponse/ConnectionResponse.pb.h"
//
//using boost::asio::ip::tcp;
//
//using namespace Jarvis;
//
//int main(int argc, char* argv[])
//{
//  try
//  {
//    if (argc != 3)
//    {
//      std::cout << "Usage: sync_client <server> <path>\n";
//      std::cout << "Example:\n";
//      std::cout << "  sync_client www.boost.org /LICENSE_1_0.txt\n";
//      return 1;
//    }
//    
//    boost::asio::io_service io_service;
//    
//    // Get a list of endpoints corresponding to the server name.
//    tcp::resolver resolver(io_service);
//    tcp::resolver::query query(argv[1], "http");
//    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
//    tcp::resolver::iterator end;
//    
//    // Try each endpoint until we successfully establish a connection.
//    tcp::socket socket(io_service);
//    boost::system::error_code error = boost::asio::error::host_not_found;
//    while (error && endpoint_iterator != end)
//    {
//      socket.close();
//      socket.connect(*endpoint_iterator++, error);
//    }
//    if (error)
//      throw boost::system::system_error(error);
//    
//    // Form the request. We specify the "Connection: close" header so that the
//    // server will close the socket after transmitting the response. This will
//    // allow us to treat all data up until the EOF as the content.
//    boost::asio::streambuf request;
//    std::ostream request_stream(&request);
//    request_stream << "GET /" << argv[2] << " HTTP/1.1\r\n";
//    request_stream << "Host: " << argv[1] << "\r\n";
//    request_stream << "User-Agent: KeepAliveClient\r\n";
//    request_stream << "Upgrade: dictation\r\n\r\n";
//    
//    // Send the request.
//    boost::asio::write(socket, request);
//    
//    // Read the response status line.
//    boost::asio::streambuf response;
//    boost::asio::read_until(socket, response, "\r\n");
//    
//    // Check that response is OK.
//    std::istream response_stream(&response);
//    std::string http_version;
//    response_stream >> http_version;
//    unsigned int status_code;
//    response_stream >> status_code;
//    std::string status_message;
//    std::getline(response_stream, status_message);
//    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
//    {
//      std::cout << "Invalid response\n";
//      return 1;
//    }
//    
//    std::cout << "Response returned with status code " << status_code << "\n";
//    
//    // Read the response headers, which are terminated by a blank line.
//    boost::asio::read_until(socket, response, "\r\n\r\n");
//    
//    // Process the response headers.
//    std::string header;
//    while (std::getline(response_stream, header) && header != "\r")
//      std::cout << header << "\n";
//    std::cout << "\n";
//    
//    // Write whatever content we already have to output.
//    if (response.size() > 0)
//      std::cout << &response;
//    
//    boost::shared_ptr<ConnectionRequest> CReq(new ConnectionRequest);
//    CReq->set_protocolversion(1);
//    CReq->set_speechkitversion("");
//    CReq->set_servicename("asr.yandex.net");
//    CReq->set_uuid("0CD748B1936933CEAA07FD7813B05877");
//    CReq->set_apikey("d9def809-0bc4-4954-b0c9-6d544d787581");
//    CReq->set_applicationname("asr_dictation");
//    CReq->set_device("macbook");
//    CReq->set_coords("0, 0");
//    CReq->set_topic("queries");
//    CReq->set_lang("ru-RU");
//    CReq->set_format("audio/x-wav");
//    CReq->PrintDebugString();
//    std::string requestCReq;
//    requestCReq = CReq->SerializeAsString();
//    std::cout << "string: " << requestCReq << std::endl;
//    boost::asio::streambuf CReq_buf;
//    std::ostream CReq_stream(&CReq_buf);
//    CReq_stream << std::hex << requestCReq.size() << "\r\n";
//    CReq_stream << requestCReq << "\r\n\r\n";
//    
//    boost::asio::read_until(socket, response, "\r\n");
//    std::istream response_stream1(&response);
//    response_stream1 >> status_code;
//    std::cout << "size: " << status_code << std::endl;
//  }
//  catch (std::exception& e)
//  {
//    std::cout << "Exception: " << e.what() << "\n";
//  }
//
//  return 0;
//}

#include <sstream>
#include <map>
#include <iostream>
#include "./JsonParser/JsonParser.hpp"

int main() {
  Jarvis::JsonParser j("configuration.json");
  std::map <std::string, std::string> map;
  map = j.parse();
  for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  return 0;
}