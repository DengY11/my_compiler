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
CMAKE_SOURCE_DIR = /home/dylan/code/my_compiler/test/lexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dylan/code/my_compiler/test/lexer/build_separator

# Include any dependencies generated for this target.
include CMakeFiles/TestSeparator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestSeparator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestSeparator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestSeparator.dir/flags.make

CMakeFiles/TestSeparator.dir/test_separator.cpp.o: CMakeFiles/TestSeparator.dir/flags.make
CMakeFiles/TestSeparator.dir/test_separator.cpp.o: /home/dylan/code/my_compiler/test/lexer/test_separator.cpp
CMakeFiles/TestSeparator.dir/test_separator.cpp.o: CMakeFiles/TestSeparator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dylan/code/my_compiler/test/lexer/build_separator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestSeparator.dir/test_separator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSeparator.dir/test_separator.cpp.o -MF CMakeFiles/TestSeparator.dir/test_separator.cpp.o.d -o CMakeFiles/TestSeparator.dir/test_separator.cpp.o -c /home/dylan/code/my_compiler/test/lexer/test_separator.cpp

CMakeFiles/TestSeparator.dir/test_separator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSeparator.dir/test_separator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dylan/code/my_compiler/test/lexer/test_separator.cpp > CMakeFiles/TestSeparator.dir/test_separator.cpp.i

CMakeFiles/TestSeparator.dir/test_separator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSeparator.dir/test_separator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dylan/code/my_compiler/test/lexer/test_separator.cpp -o CMakeFiles/TestSeparator.dir/test_separator.cpp.s

# Object files for target TestSeparator
TestSeparator_OBJECTS = \
"CMakeFiles/TestSeparator.dir/test_separator.cpp.o"

# External object files for target TestSeparator
TestSeparator_EXTERNAL_OBJECTS =

TestSeparator: CMakeFiles/TestSeparator.dir/test_separator.cpp.o
TestSeparator: CMakeFiles/TestSeparator.dir/build.make
TestSeparator: libLexerLib.a
TestSeparator: libTokenLib.a
TestSeparator: CMakeFiles/TestSeparator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dylan/code/my_compiler/test/lexer/build_separator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSeparator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSeparator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestSeparator.dir/build: TestSeparator
.PHONY : CMakeFiles/TestSeparator.dir/build

CMakeFiles/TestSeparator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestSeparator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestSeparator.dir/clean

CMakeFiles/TestSeparator.dir/depend:
	cd /home/dylan/code/my_compiler/test/lexer/build_separator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dylan/code/my_compiler/test/lexer /home/dylan/code/my_compiler/test/lexer /home/dylan/code/my_compiler/test/lexer/build_separator /home/dylan/code/my_compiler/test/lexer/build_separator /home/dylan/code/my_compiler/test/lexer/build_separator/CMakeFiles/TestSeparator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestSeparator.dir/depend

