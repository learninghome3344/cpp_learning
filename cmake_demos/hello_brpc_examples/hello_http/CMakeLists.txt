cmake_minimum_required(VERSION 3.5)
project(hello_http)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "/Users/bingjian.yan/recent_learning/network_learning/incubator-brpc/build/output")

include(FindThreads)

include(FindProtobuf)
message(WARNING "0: ${Protobuf_INCLUDE_DIRS} ${Protobuf_LIBRARIES}")
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER http.proto)
message(WARNING "1: ${PROTO_SRC} ${PROTO_HEADER}")

find_path(BRPC_INCLUDE_PATH NAMES brpc/server.h) # 在CMAKE_PREFIX_PATH可以找到，不需要再配置PATHS 
message(WARNING "2: ${BRPC_INCLUDE_PATH}")
include_directories(${BRPC_INCLUDE_PATH})
find_library(BRPC_LIB NAMES libbrpc.a)
message(WARNING "3: ${BRPC_LIB}")

find_path(GFLAGS_INCLUDE_PATH gflags/gflags.h)         
message(WARNING "4: ${GFLAGS_INCLUDE_PATH}")
find_library(GFLAGS_LIBRARY NAMES gflags libgflags)
message(WARNING "5: ${GFLAGS_LIBRARY}")
include_directories(${GFLAGS_INCLUDE_PATH})

find_path(LEVELDB_INCLUDE_PATH NAMES leveldb/db.h)
find_library(LEVELDB_LIB NAMES leveldb)
include_directories(${LEVELDB_INCLUDE_PATH})

find_package(OpenSSL)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(http_server http_server.cpp ${PROTO_SRC} ${PROTO_HEADER})  
add_executable(http_client http_client.cpp ${PROTO_SRC} ${PROTO_HEADER})

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
target_link_libraries(http_server ${BRPC_LIB} ${DYNAMIC_LIB})
target_link_libraries(http_client ${BRPC_LIB} ${DYNAMIC_LIB})
