cmake_minimum_required(VERSION 2.6)
project(SmartHome)

set(GPP14 -std=c++14)
set(WALL -Wall)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP14} ${WALL}")

set(SERIALPORT_SOURCE src/SerialPort.cpp)
set(DEVICE_SOURCE src/Device.cpp)
set(BULB_SOURCE src/Bulb.cpp)
set(MODULE_SOURCE src/Module.cpp)
set(DEVICES_SOURCE src/Devices.cpp)
set(BULB_SOURCE src/Bulb.cpp)
set(TEAPOT_SOURCE src/Teapot.cpp)
set(BLUETOOTH_SOURCE src/BluetoothHC05.cpp)

set(BOOST_ROOT /opt/boost/)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(BOOST_COMPONENTS system)

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_library(SmartHomeLib STATIC ${SERIALPORT_SOURCE} ${DEVICE_SOURCE} ${BULB_SOURCE} ${MODULE_SOURCE} ${DEVICES_SOURCE} ${BULB_SOURCE} ${TEAPOT_SOURCE} ${BLUETOOTH_SOURCE})

  add_executable(tests ${TESTS_SOURCE} tests/test.cpp)

  target_link_libraries(tests ${Boost_LIBRARIES} SmartHomeLib)
endif()
