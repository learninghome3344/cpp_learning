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
CMAKE_SOURCE_DIR = /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_protobuf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_protobuf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_protobuf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_protobuf.dir/flags.make

AddressBook.pb.h: ../AddressBook.proto
AddressBook.pb.h: /Users/bingjian.yan/Documents/protobuf/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on AddressBook.proto"
	/Users/bingjian.yan/Documents/protobuf/bin/protoc --cpp_out /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build -I /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/AddressBook.proto

AddressBook.pb.cc: AddressBook.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate AddressBook.pb.cc

CMakeFiles/hello_protobuf.dir/main.cpp.o: CMakeFiles/hello_protobuf.dir/flags.make
CMakeFiles/hello_protobuf.dir/main.cpp.o: ../main.cpp
CMakeFiles/hello_protobuf.dir/main.cpp.o: CMakeFiles/hello_protobuf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hello_protobuf.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_protobuf.dir/main.cpp.o -MF CMakeFiles/hello_protobuf.dir/main.cpp.o.d -o CMakeFiles/hello_protobuf.dir/main.cpp.o -c /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/main.cpp

CMakeFiles/hello_protobuf.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_protobuf.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/main.cpp > CMakeFiles/hello_protobuf.dir/main.cpp.i

CMakeFiles/hello_protobuf.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_protobuf.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/main.cpp -o CMakeFiles/hello_protobuf.dir/main.cpp.s

CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o: CMakeFiles/hello_protobuf.dir/flags.make
CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o: AddressBook.pb.cc
CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o: CMakeFiles/hello_protobuf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o -MF CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o.d -o CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o -c /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/AddressBook.pb.cc

CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/AddressBook.pb.cc > CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.i

CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/AddressBook.pb.cc -o CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.s

# Object files for target hello_protobuf
hello_protobuf_OBJECTS = \
"CMakeFiles/hello_protobuf.dir/main.cpp.o" \
"CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o"

# External object files for target hello_protobuf
hello_protobuf_EXTERNAL_OBJECTS =

hello_protobuf: CMakeFiles/hello_protobuf.dir/main.cpp.o
hello_protobuf: CMakeFiles/hello_protobuf.dir/AddressBook.pb.cc.o
hello_protobuf: CMakeFiles/hello_protobuf.dir/build.make
hello_protobuf: /usr/local/lib/libprotobuf.dylib
hello_protobuf: CMakeFiles/hello_protobuf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable hello_protobuf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_protobuf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_protobuf.dir/build: hello_protobuf
.PHONY : CMakeFiles/hello_protobuf.dir/build

CMakeFiles/hello_protobuf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_protobuf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_protobuf.dir/clean

CMakeFiles/hello_protobuf.dir/depend: AddressBook.pb.cc
CMakeFiles/hello_protobuf.dir/depend: AddressBook.pb.h
	cd /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_protobuf/build/CMakeFiles/hello_protobuf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_protobuf.dir/depend
