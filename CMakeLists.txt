cmake_minimum_required(VERSION 2.6)
project(Jarvis)

set(GPP14 -std=c++14)
set(WALL -Wall)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP14} ${WALL} -lcurl")
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
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ src/ tests/)

  add_library(Jarvis STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Transport.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Command.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/SerialPort.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/SpeechKit.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Voice.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/MediatorCreator.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/YandexSpeechKitMediator.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Jarvis.cpp)

  add_executable(tests ${TESTS_SOURCE} tests/test.cpp)
  target_link_libraries(tests ${Boost_LIBRARIES} Jarvis)
endif()
