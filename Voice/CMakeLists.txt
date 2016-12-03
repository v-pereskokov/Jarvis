cmake_minimum_required(VERSION 2.8.7)

project(Jarvis CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -I/opt/local/include -L/opt/local/lib -lboost_system -lcurl")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS asio utility property_tree REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} /tests/)
include_directories(${Boost_INCLUDE_DIRS})

add_library(Jarvis STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Jarvis.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)

add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/tests/JarvisTest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)

target_link_libraries(test ${Boost_LIBRARIES})
