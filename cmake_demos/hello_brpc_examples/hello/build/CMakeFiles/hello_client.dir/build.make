# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_client.dir/flags.make

hello.pb.h: ../hello.proto
hello.pb.h: /Users/bingjian.yan/Documents/protobuf/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on hello.proto"
	/Users/bingjian.yan/Documents/protobuf/bin/protoc --cpp_out /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build -I /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/hello.proto

hello.pb.cc: hello.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate hello.pb.cc

CMakeFiles/hello_client.dir/client.cpp.o: CMakeFiles/hello_client.dir/flags.make
CMakeFiles/hello_client.dir/client.cpp.o: ../client.cpp
CMakeFiles/hello_client.dir/client.cpp.o: CMakeFiles/hello_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hello_client.dir/client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_client.dir/client.cpp.o -MF CMakeFiles/hello_client.dir/client.cpp.o.d -o CMakeFiles/hello_client.dir/client.cpp.o -c /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/client.cpp

CMakeFiles/hello_client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_client.dir/client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/client.cpp > CMakeFiles/hello_client.dir/client.cpp.i

CMakeFiles/hello_client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_client.dir/client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/client.cpp -o CMakeFiles/hello_client.dir/client.cpp.s

CMakeFiles/hello_client.dir/hello.pb.cc.o: CMakeFiles/hello_client.dir/flags.make
CMakeFiles/hello_client.dir/hello.pb.cc.o: hello.pb.cc
CMakeFiles/hello_client.dir/hello.pb.cc.o: CMakeFiles/hello_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hello_client.dir/hello.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_client.dir/hello.pb.cc.o -MF CMakeFiles/hello_client.dir/hello.pb.cc.o.d -o CMakeFiles/hello_client.dir/hello.pb.cc.o -c /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc

CMakeFiles/hello_client.dir/hello.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_client.dir/hello.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc > CMakeFiles/hello_client.dir/hello.pb.cc.i

CMakeFiles/hello_client.dir/hello.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_client.dir/hello.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc -o CMakeFiles/hello_client.dir/hello.pb.cc.s

# Object files for target hello_client
hello_client_OBJECTS = \
"CMakeFiles/hello_client.dir/client.cpp.o" \
"CMakeFiles/hello_client.dir/hello.pb.cc.o"

# External object files for target hello_client
hello_client_EXTERNAL_OBJECTS =

hello_client: CMakeFiles/hello_client.dir/client.cpp.o
hello_client: CMakeFiles/hello_client.dir/hello.pb.cc.o
hello_client: CMakeFiles/hello_client.dir/build.make
hello_client: /Users/bingjian.yan/recent_learning/network_learning/incubator-brpc/build/output/lib/libbrpc.a
hello_client: /usr/local/lib/libgflags.a
hello_client: /usr/local/lib/libprotobuf.dylib
hello_client: /usr/local/lib/libleveldb.dylib
hello_client: /usr/local/Cellar/openssl@3/3.0.1/lib/libcrypto.dylib
hello_client: /usr/local/Cellar/openssl@3/3.0.1/lib/libssl.dylib
hello_client: CMakeFiles/hello_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable hello_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_client.dir/build: hello_client
.PHONY : CMakeFiles/hello_client.dir/build

CMakeFiles/hello_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_client.dir/clean

CMakeFiles/hello_client.dir/depend: hello.pb.cc
CMakeFiles/hello_client.dir/depend: hello.pb.h
	cd /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles/hello_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_client.dir/depend
