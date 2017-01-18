#include "../include/BluetoothHC05.hpp"
#include <iostream>
namespace Jarvis {
  namespace Connection {
    namespace Bluetooth {
      BluetoothHC05::BluetoothHC05(const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
      :_port(new port(portName, portRate)) {}
      
      BluetoothHC05::~BluetoothHC05() {
        delete _port;
      }
      
      BluetoothHC05::answers BluetoothHC05::getNameDevice(const address &address) {
        connect();
        command(ATCommands::RNAME + address);
        deviceName name = getNameFromAnswerRname(getAnswer());
        disconnect();
        return name;
      }
      
      BluetoothHC05::listDevices BluetoothHC05::getListDevicesAddress() {
        connect();
        command(ATCommands::INIT);
        getAnswer();
        command(ATCommands::INQUIRE);
        listDevices list;
        findListDevicesAddress(&list, getAnswer());
        disconnect();
        return list;
      }
      
      BluetoothHC05::listDevices BluetoothHC05::getListDevicesName() {
        auto list = getListDevicesAddress();
        changeListElements(&list, [&](deviceName &device){ return getNameDevice(device); });
        return list;
      }
      
      BluetoothHC05::listDevices BluetoothHC05::getListDevicesPortName() {
        auto list = getListDevicesName();
        changeListElements(&list, [&](const deviceName &device){ return makePortName(device); });
        return list;
      }
      
      BluetoothHC05::listOfPair BluetoothHC05::getListOfDevicePortName() {
        auto listName = getListDevicesName();
        auto listPort = listName;
        makeListDevicesPortName(&listPort);
        listOfPair result;
        for (devicesCount i = 0; i < listPort.size(); ++i) {
          result.push_back({listName[i], listPort[i]});
        }
        return result;
      }
      
      void BluetoothHC05::connect() {
        _port->connect();
      }
      
      void BluetoothHC05::disconnect() {
        _port->disconnect();
      }
      
      BluetoothHC05::deviceName BluetoothHC05::getNameFromAnswerRname(const answers &answer) {
        return findValue(answer, "OK");
      }
      
      void BluetoothHC05::command(const query &query) {
        _port->write(query);
      }
      
      BluetoothHC05::answers BluetoothHC05::getAnswer() {
        answers answer;
        answers part;
        while (part != ATCommands::SUCCESS) {
          part =_port->read();
          answer += part;
        }
        return answer;
      }
      
      BluetoothHC05::answers BluetoothHC05::findValue(const answers &answer, const answers &edge) {
        return deviceName(answer.begin() + answer.find(":") + 1, answer.begin() + answer.find(edge));
      }
      
      void BluetoothHC05::findListDevicesAddress(listDevices *list, const answers &answer) {
        answers address;
        auto target = answer;
        auto count = getDevicesCount(answer);
        target.erase(0, target.find_first_of("+") + 1);
        for (devicesCount i = 0; i < count; ++i) {
          address = findValue(target, ",");
          std::replace(address.begin(), address.end(), ':', ',');
          list->push_back(address);
          target.erase(0, ((i != count - 1) ? (target.find_first_of("+")) : target.find_first_of("OK")));
        }
      }
      
      BluetoothHC05::devicesCount BluetoothHC05::getDevicesCount(const answers &answer) const {
        return std::count(answer.begin(), answer.end(), '+');
      }
      
      BluetoothHC05::portName BluetoothHC05::makePortName(const deviceName &name) {
        return "/dev/cu." + name + "-DevB";
      }
      
      void BluetoothHC05::makeListDevicesPortName(listDevices *list) {
        changeListElements(list, [&](const deviceName &device){ return makePortName(device); });
      }
    }
  }
}
