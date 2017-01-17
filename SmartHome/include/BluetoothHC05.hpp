#pragma once

#ifndef BLUETOOTHHC05_H
#define BLUETOOTHHC05_H

#include <string>
#include <vector>
#include <utility>
#include <chrono>
#include <thread>
#include <algorithm>
#include "SerialPort.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Connection
   * \brief Для подключения к Arduino
   */
  namespace Connection {
    namespace Bluetooth {
#define methods
#define params
#define usings
#define structs
      namespace ATCommands {
        using ATCommand = std::string;
        
        const ATCommand INIT = "init";
        const ATCommand NAME = "name";
        const ATCommand RNAME = "rname_";
        const ATCommand INQM = "inqm=";
        const ATCommand INQUIRE = "inq";
        const ATCommand PAIR = "pair=";
        const ATCommand LINK = "link_";
        const ATCommand DISCONNECTION = "disc";
        const ATCommand ROLE = "cmode_";
        const ATCommand SUCCESS = "OK";
      }
      
      class BluetoothHC05 {
        using port = Connection::SerialPort;
        using answers = std::string;
        using deviceName = std::string;
        using address = std::string;
        using listDevices = std::vector<address>;
        using query = std::string;
        using devicesCount = std::size_t;
        using portName = std::string;
        using deviceNamePortPair = std::pair<deviceName, portName>;
        using listOfPair = std::vector<deviceNamePortPair>;
        
        public methods:
        BluetoothHC05(const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate = 9600);
        ~BluetoothHC05();
        
        answers getNameDevice(const address &address);
        listDevices getListDevicesAddress();
        listDevices getListDevicesName();
        listDevices getListDevicesPortName();
        listOfPair getListOfDevicePortName();
        
        private methods:
        BluetoothHC05() = delete;
        BluetoothHC05(const BluetoothHC05 &copy) = delete;
        BluetoothHC05(BluetoothHC05 &&copy) = delete;
        BluetoothHC05& operator=(const BluetoothHC05 &copy) = delete;
        BluetoothHC05& operator=(BluetoothHC05 &&copy) = delete;
        
        void connect();
        void disconnect();
        deviceName getNameFromAnswerRname(const answers &answer);
        void command(const query &query);
        void clear(answers *answer);
        answers getAnswer();
        answers findValue(const answers &answer, const answers &edge);
        void findListDevicesAddress(listDevices *list, const answers &answer);
        devicesCount getDevicesCount(const answers &answer) const;
        portName makePortName(const deviceName &name);
        listDevices getListDevicesPortName(listDevices *list);
        
        template <class Predicate>
        void changeListElements(listDevices *list, Predicate pred) {
          for (devicesCount i = 0; i < list->size(); ++i) {
            (*list)[i] = pred((*list)[i]);
          }
        }
        
        private params:
        port *_port;
      };
    }
  }
}

#endif // BLUETOOTHHC05_H
