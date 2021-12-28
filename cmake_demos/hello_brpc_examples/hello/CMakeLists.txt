
# https://www.codeleading.com/article/74325974403/

cmake_minimum_required(VERSION 3.5) # 指定最低版本

project(hello_brpc) # 设置工程名

set(CMAKE_CXX_STANDARD 11) # 设置c++ version

# 在CMAKE_PREFIX_PATH变量所表示的路径下寻找, CMAKE_PREFIX_PATH有最高的查找优先级, 在find_package()参数列表中填写NO_CMAKE_PATH则跳过该查找项。
set(CMAKE_PREFIX_PATH "/Users/bingjian.yan/recent_learning/network_learning/incubator-brpc/build/output")

include(FindThreads) # 引入thread库

# cmake自带搜索protobuf，把protobuf相关库文件包含进来
include(FindProtobuf)
message(WARNING "0: ${Protobuf_INCLUDE_DIRS} ${Protobuf_LIBRARIES}")
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER hello.proto)
message(WARNING "1: ${PROTO_SRC} ${PROTO_HEADER}")
# include_directories(${CMAKE_CURRENT_BINARY_DIR})

#搜索brpc头文件和库文件路径
find_path(BRPC_INCLUDE_PATH NAMES brpc/server.h) # 在CMAKE_PREFIX_PATH可以找到，不需要再配置PATHS 
message(WARNING "2: ${BRPC_INCLUDE_PATH}")
include_directories(${BRPC_INCLUDE_PATH})
find_library(BRPC_LIB NAMES libbrpc.a)
message(WARNING "3: ${BRPC_LIB}")

# #搜索gflags相关依赖，这个主要是解析命令行参数的，用不到可以不搜索
find_path(GFLAGS_INCLUDE_PATH gflags/gflags.h)         
message(WARNING "4: ${GFLAGS_INCLUDE_PATH}")
find_library(GFLAGS_LIBRARY NAMES gflags libgflags)
message(WARNING "5: ${GFLAGS_LIBRARY}")
include_directories(${GFLAGS_INCLUDE_PATH})

#搜索leveldb相关依赖
find_path(LEVELDB_INCLUDE_PATH NAMES leveldb/db.h)
find_library(LEVELDB_LIB NAMES leveldb)
include_directories(${LEVELDB_INCLUDE_PATH})

#brpc必须要openssl的lib
find_package(OpenSSL)
include_directories(${OPENSSL_INCLUDE_DIR})

#使用server.cpp ${PROTO_SRC} ${PROTO_HEADER}生成可执行文件hello_server
add_executable(hello_server server.cpp ${PROTO_SRC} ${PROTO_HEADER})  

#使用client.cpp ${PROTO_SRC} ${PROTO_HEADER}生成可执行文件hello_client
add_executable(hello_client client.cpp ${PROTO_SRC} ${PROTO_HEADER})

#添加BRPC所需要的lib
set(DYNAMIC_LIB             
    ${CMAKE_THREAD_LIBS_INIT}
    ${GFLAGS_LIBRARY}
    ${PROTOBUF_LIBRARIES}
    ${LEVELDB_LIB}
    ${OPENSSL_CRYPTO_LIBRARY}
    ${OPENSSL_SSL_LIBRARY}
    dl
)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(DYNAMIC_LIB ${DYNAMIC_LIB}
        pthread
        "-framework CoreFoundation"
        "-framework CoreGraphics"
        "-framework CoreData"
        "-framework CoreText"
        "-framework Security"
        "-framework Foundation"
        "-Wl,-U,_MallocExtension_ReleaseFreeMemory"
        "-Wl,-U,_ProfilerStart"
        "-Wl,-U,_ProfilerStop")
endif()

#将目标文件与库文件进行链接
target_link_libraries(hello_server ${BRPC_LIB} ${DYNAMIC_LIB})
target_link_libraries(hello_client ${BRPC_LIB} ${DYNAMIC_LIB})
