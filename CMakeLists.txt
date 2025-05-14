cmake_minimum_required(VERSION 3.28.3)
project(networking)

set(CMAKE_CXX_STANDARD 23)

add_executable(keygen keygen.cpp)
#add_executable(client client.cpp)
add_executable(server server.cpp)
#add_executable(dec_client dec_client.cpp)
#add_executable(dec_server dec_server.cpp)
