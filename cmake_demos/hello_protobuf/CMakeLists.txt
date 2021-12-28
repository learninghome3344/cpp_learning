cmake_minimum_required(VERSION 3.5)

# Set the project name
project (hello_protobuf)

# find the protobuf compiler and libraries
find_package(Protobuf REQUIRED)

# check if protobuf was found
if(PROTOBUF_FOUND)
    message ("protobuf found")
else()
    message (FATAL_ERROR "Cannot find Protobuf")
endif()

# Generate the .h and .cxx files
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS AddressBook.proto)

# Print path to generated files
message ("PROTO_SRCS = ${PROTO_SRCS}")
message ("PROTO_HDRS = ${PROTO_HDRS}")

# Add an executable
add_executable(hello_protobuf
    main.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS})

target_include_directories(hello_protobuf
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# link the exe against the libraries
target_link_libraries(hello_protobuf
    PUBLIC
    ${PROTOBUF_LIBRARIES}
)
