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
CMAKE_SOURCE_DIR = /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build

# Include any dependencies generated for this target.
include CMakeFiles/third_party_include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/third_party_include.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/third_party_include.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/third_party_include.dir/flags.make

CMakeFiles/third_party_include.dir/main.cpp.o: CMakeFiles/third_party_include.dir/flags.make
CMakeFiles/third_party_include.dir/main.cpp.o: ../main.cpp
CMakeFiles/third_party_include.dir/main.cpp.o: CMakeFiles/third_party_include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/third_party_include.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/third_party_include.dir/main.cpp.o -MF CMakeFiles/third_party_include.dir/main.cpp.o.d -o CMakeFiles/third_party_include.dir/main.cpp.o -c /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/main.cpp

CMakeFiles/third_party_include.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/third_party_include.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/main.cpp > CMakeFiles/third_party_include.dir/main.cpp.i

CMakeFiles/third_party_include.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/third_party_include.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/main.cpp -o CMakeFiles/third_party_include.dir/main.cpp.s

# Object files for target third_party_include
third_party_include_OBJECTS = \
"CMakeFiles/third_party_include.dir/main.cpp.o"

# External object files for target third_party_include
third_party_include_EXTERNAL_OBJECTS =

third_party_include: CMakeFiles/third_party_include.dir/main.cpp.o
third_party_include: CMakeFiles/third_party_include.dir/build.make
third_party_include: /usr/local/lib/libboost_filesystem-mt.dylib
third_party_include: CMakeFiles/third_party_include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable third_party_include"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/third_party_include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/third_party_include.dir/build: third_party_include
.PHONY : CMakeFiles/third_party_include.dir/build

CMakeFiles/third_party_include.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/third_party_include.dir/cmake_clean.cmake
.PHONY : CMakeFiles/third_party_include.dir/clean

CMakeFiles/third_party_include.dir/depend:
	cd /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build /Users/bingjian.yan/recent_learning/network_learning/cmake-examples-Chinese/hello_third_party/build/CMakeFiles/third_party_include.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/third_party_include.dir/depend
