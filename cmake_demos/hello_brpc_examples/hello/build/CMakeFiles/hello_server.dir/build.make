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
include CMakeFiles/hello_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_server.dir/flags.make

hello.pb.h: ../hello.proto
hello.pb.h: /Users/bingjian.yan/Documents/protobuf/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on hello.proto"
	/Users/bingjian.yan/Documents/protobuf/bin/protoc --cpp_out /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build -I /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/hello.proto

hello.pb.cc: hello.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate hello.pb.cc

CMakeFiles/hello_server.dir/server.cpp.o: CMakeFiles/hello_server.dir/flags.make
CMakeFiles/hello_server.dir/server.cpp.o: ../server.cpp
CMakeFiles/hello_server.dir/server.cpp.o: CMakeFiles/hello_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hello_server.dir/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_server.dir/server.cpp.o -MF CMakeFiles/hello_server.dir/server.cpp.o.d -o CMakeFiles/hello_server.dir/server.cpp.o -c /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/server.cpp

CMakeFiles/hello_server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_server.dir/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/server.cpp > CMakeFiles/hello_server.dir/server.cpp.i

CMakeFiles/hello_server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_server.dir/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/server.cpp -o CMakeFiles/hello_server.dir/server.cpp.s

CMakeFiles/hello_server.dir/hello.pb.cc.o: CMakeFiles/hello_server.dir/flags.make
CMakeFiles/hello_server.dir/hello.pb.cc.o: hello.pb.cc
CMakeFiles/hello_server.dir/hello.pb.cc.o: CMakeFiles/hello_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hello_server.dir/hello.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_server.dir/hello.pb.cc.o -MF CMakeFiles/hello_server.dir/hello.pb.cc.o.d -o CMakeFiles/hello_server.dir/hello.pb.cc.o -c /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc

CMakeFiles/hello_server.dir/hello.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_server.dir/hello.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc > CMakeFiles/hello_server.dir/hello.pb.cc.i

CMakeFiles/hello_server.dir/hello.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_server.dir/hello.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/hello.pb.cc -o CMakeFiles/hello_server.dir/hello.pb.cc.s

# Object files for target hello_server
hello_server_OBJECTS = \
"CMakeFiles/hello_server.dir/server.cpp.o" \
"CMakeFiles/hello_server.dir/hello.pb.cc.o"

# External object files for target hello_server
hello_server_EXTERNAL_OBJECTS =

hello_server: CMakeFiles/hello_server.dir/server.cpp.o
hello_server: CMakeFiles/hello_server.dir/hello.pb.cc.o
hello_server: CMakeFiles/hello_server.dir/build.make
hello_server: /Users/bingjian.yan/recent_learning/network_learning/incubator-brpc/build/output/lib/libbrpc.a
hello_server: /usr/local/lib/libgflags.a
hello_server: /usr/local/lib/libprotobuf.dylib
hello_server: /usr/local/lib/libleveldb.dylib
hello_server: /usr/local/Cellar/openssl@3/3.0.1/lib/libcrypto.dylib
hello_server: /usr/local/Cellar/openssl@3/3.0.1/lib/libssl.dylib
hello_server: CMakeFiles/hello_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable hello_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_server.dir/build: hello_server
.PHONY : CMakeFiles/hello_server.dir/build

CMakeFiles/hello_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_server.dir/clean

CMakeFiles/hello_server.dir/depend: hello.pb.cc
CMakeFiles/hello_server.dir/depend: hello.pb.h
	cd /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build /Users/bingjian.yan/recent_learning/hello_demo/cpp_demo/hello_brpc/build/CMakeFiles/hello_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_server.dir/depend

