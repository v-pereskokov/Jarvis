cmake_minimum_required(VERSION 2.6)
project(Jarvis)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(WALL -Wall)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WALL} -lcurl")

set(${PROJECT_NAME}_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})
file(GLOB ${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(BOOST_ROOT /opt/boost/)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(BOOST_COMPONENTS system)

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
find_package(OpenSSL)
find_package(CURL)

include_directories(${CURL_INCLUDE_DIR})

if(UNIX)
    set(DEPENDS_LIBRARIES ${OPENSSL_LIBRARIES} ${CURL_LIBRARY})
endif()

if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})
endif()