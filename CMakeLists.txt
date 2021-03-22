cmake_minimum_required(VERSION 3.16.3)

set (LEVELDB_DIR "/home/sharonf/workspace/leveldb")
set(THREADS_PREFER_PTHREAD_FLAG ON)

# set the project name
project(hello_leveldb VERSION 1.0)

# add the executable
add_executable(hello_leveldb hello_leveldb.cpp)

# leveldb include library
target_include_directories(hello_leveldb PUBLIC "${LEVELDB_DIR}/include")

# leveldb library, pthread library
find_package(Threads REQUIRED)
add_library(leveldb STATIC IMPORTED)
set_target_properties(leveldb PROPERTIES 
    IMPORTED_LOCATION "${LEVELDB_DIR}/build/libleveldb.a")
target_link_libraries(hello_leveldb leveldb Threads::Threads)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

