cmake_minimum_required(VERSION 3.5)

project(hello_gflags)
set(CMAKE_CXX_STANDARD 11) # same as set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11"), cmake3.1引入

find_package(gflags REQUIRED)
include_directories(${gflags_INCLUDE_DIR})
find_package(glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIR})

add_executable(hello_gflags 
    main.cpp
)
target_link_libraries(hello_gflags 
    glog::glog 
    gflags
)

