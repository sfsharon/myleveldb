cmake_minimum_required(VERSION 3.16.3)

# set the project name
project(hello_leveldb VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(hello_leveldb hello_leveldb.cpp)

# configure_file(hello_leveldb.h in hello_leveldb.h)

target_include_directories(hello_leveldb PUBLIC 
                            "/home/sharonf/workspace/leveldb"
                            )
