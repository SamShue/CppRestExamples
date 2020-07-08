# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(restserver)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Added for force C++11 build options
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

find_package(Boost REQUIRED system)
find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

set(LINK_LIBRARIES pthread rt SDL2 jsoncpp_static cpprest OpenSSL::Crypto ${Boost_SYSTEM_LIBRARY})


add_executable(restserver main.cpp restServer.cpp)
target_link_libraries(restserver ${LINK_LIBRARIES})