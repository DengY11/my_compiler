# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dylan/code/my_compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dylan/code/my_compiler/build

# Include any dependencies generated for this target.
include test/token/CMakeFiles/TestToken.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/token/CMakeFiles/TestToken.dir/compiler_depend.make

# Include the progress variables for this target.
include test/token/CMakeFiles/TestToken.dir/progress.make

# Include the compile flags for this target's objects.
include test/token/CMakeFiles/TestToken.dir/flags.make

test/token/CMakeFiles/TestToken.dir/test_token.cpp.o: test/token/CMakeFiles/TestToken.dir/flags.make
test/token/CMakeFiles/TestToken.dir/test_token.cpp.o: /home/dylan/code/my_compiler/test/token/test_token.cpp
test/token/CMakeFiles/TestToken.dir/test_token.cpp.o: test/token/CMakeFiles/TestToken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dylan/code/my_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/token/CMakeFiles/TestToken.dir/test_token.cpp.o"
	cd /home/dylan/code/my_compiler/build/test/token && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/token/CMakeFiles/TestToken.dir/test_token.cpp.o -MF CMakeFiles/TestToken.dir/test_token.cpp.o.d -o CMakeFiles/TestToken.dir/test_token.cpp.o -c /home/dylan/code/my_compiler/test/token/test_token.cpp

test/token/CMakeFiles/TestToken.dir/test_token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestToken.dir/test_token.cpp.i"
	cd /home/dylan/code/my_compiler/build/test/token && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/code/my_compiler/test/token/test_token.cpp > CMakeFiles/TestToken.dir/test_token.cpp.i

test/token/CMakeFiles/TestToken.dir/test_token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestToken.dir/test_token.cpp.s"
	cd /home/dylan/code/my_compiler/build/test/token && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/code/my_compiler/test/token/test_token.cpp -o CMakeFiles/TestToken.dir/test_token.cpp.s

# Object files for target TestToken
TestToken_OBJECTS = \
"CMakeFiles/TestToken.dir/test_token.cpp.o"

# External object files for target TestToken
TestToken_EXTERNAL_OBJECTS =

test/token/TestToken: test/token/CMakeFiles/TestToken.dir/test_token.cpp.o
test/token/TestToken: test/token/CMakeFiles/TestToken.dir/build.make
test/token/TestToken: libMyCompilerLib.a
test/token/TestToken: test/token/CMakeFiles/TestToken.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dylan/code/my_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestToken"
	cd /home/dylan/code/my_compiler/build/test/token && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestToken.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/token/CMakeFiles/TestToken.dir/build: test/token/TestToken
.PHONY : test/token/CMakeFiles/TestToken.dir/build

test/token/CMakeFiles/TestToken.dir/clean:
	cd /home/dylan/code/my_compiler/build/test/token && $(CMAKE_COMMAND) -P CMakeFiles/TestToken.dir/cmake_clean.cmake
.PHONY : test/token/CMakeFiles/TestToken.dir/clean

test/token/CMakeFiles/TestToken.dir/depend:
	cd /home/dylan/code/my_compiler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dylan/code/my_compiler /home/dylan/code/my_compiler/test/token /home/dylan/code/my_compiler/build /home/dylan/code/my_compiler/build/test/token /home/dylan/code/my_compiler/build/test/token/CMakeFiles/TestToken.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/token/CMakeFiles/TestToken.dir/depend

