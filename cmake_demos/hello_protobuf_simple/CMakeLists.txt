cmake_minimum_required(VERSION 3.5)
project(pb_learning)

find_package(Protobuf REQUIRED)
if (PROTOBUF_FOUND)
    message("protobuf found!")
else()
    message(FATAL_ERROR "Cannot find protobuf")
endif()

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS addressbook.proto)
message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")

add_executable(pb_learning
    main.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS})

target_include_directories(pb_learning
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(pb_learning
    PUBLIC
    ${PROTOBUF_LIBRARIES}
)
