cmake_minimum_required(VERSION 2.6)
project(Jarvis)

set(GPP14 -std=c++14)
set(WALL -Wall)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP14} ${WALL} -lcurl")

set(TRANSPORT_SOURCE src/Transport.cpp)
set(PARSER_SOURCE src/Parser.cpp)
set(COMMAND_SOURCE src/Command.cpp)
set(SERIAL_PORT_SOURCE src/SerialPort.cpp)
set(SPEECHKIT_SOURCE src/SpeechKit.cpp)
set(VOICE_SOURCE src/Voice.cpp)
set(JARVIS_SOURCE src/Jarvis.cpp)

set(BOOST_ROOT /opt/boost/)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(BOOST_COMPONENTS system)

find_package(Boost 1.63.0 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})

if(UNIX)
    set(DEPENDS_LIBRARIES ${OPENSSL_LIBRARIES} ${CURL_LIBRARY})
endif()

if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_library(Jarvis STATIC ${JARVIS_SOURCE} ${VOICE_SOURCE} ${SPEECHKIT_SOURCE} ${SERIAL_PORT_SOURCE} ${COMMAND_SOURCE} ${PARSER_SOURCE} ${TRANSPORT_SOURCE})

  add_executable(tests ${TESTS_SOURCE} tests/test.cpp)
  target_link_libraries(tests ${Boost_LIBRARIES} Jarvis)
endif()
