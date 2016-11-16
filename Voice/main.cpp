//#include "Jarvis/run.cpp"
//
//int main() {
//  return run();
//}

#include <iostream>
#include "Jarvis/SerialPort.hpp"

int main(int argc, char* argv[])
{
  try {
    
    Jarvis::Arduino::Connection::SerialPort serial("/dev/cu.usbmodem1411", 9600);
    std::string s;
    while (s != "stop") {
      std::getline(std::cin, s);
      serial.write(s);
      
      //      cout<<serial.readLine()<<endl;
    }
    
  } catch(boost::system::system_error& e)
  {
  std::cout<<"Error: "<<e.what()<<std::endl;
  return 1;
  }
}
