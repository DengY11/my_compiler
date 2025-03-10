# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/humgic/Applications/my_compiler/test/lexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/humgic/Applications/my_compiler/test/lexer/build

# Include any dependencies generated for this target.
include CMakeFiles/TestLexerComprehensive.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestLexerComprehensive.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestLexerComprehensive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestLexerComprehensive.dir/flags.make

CMakeFiles/TestLexerComprehensive.dir/codegen:
.PHONY : CMakeFiles/TestLexerComprehensive.dir/codegen

CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o: CMakeFiles/TestLexerComprehensive.dir/flags.make
CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o: /Users/humgic/Applications/my_compiler/test/lexer/test_lexer_comprehensive.cpp
CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o: CMakeFiles/TestLexerComprehensive.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/lexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o -MF CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o.d -o CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o -c /Users/humgic/Applications/my_compiler/test/lexer/test_lexer_comprehensive.cpp

CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/lexer/test_lexer_comprehensive.cpp > CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.i

CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/lexer/test_lexer_comprehensive.cpp -o CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.s

# Object files for target TestLexerComprehensive
TestLexerComprehensive_OBJECTS = \
"CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o"

# External object files for target TestLexerComprehensive
TestLexerComprehensive_EXTERNAL_OBJECTS =

TestLexerComprehensive: CMakeFiles/TestLexerComprehensive.dir/test_lexer_comprehensive.cpp.o
TestLexerComprehensive: CMakeFiles/TestLexerComprehensive.dir/build.make
TestLexerComprehensive: libLexerLib.a
TestLexerComprehensive: libTokenLib.a
TestLexerComprehensive: /opt/homebrew/lib/libgtest.a
TestLexerComprehensive: /opt/homebrew/lib/libgtest_main.a
TestLexerComprehensive: /opt/homebrew/lib/libgtest.a
TestLexerComprehensive: CMakeFiles/TestLexerComprehensive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/lexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestLexerComprehensive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestLexerComprehensive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestLexerComprehensive.dir/build: TestLexerComprehensive
.PHONY : CMakeFiles/TestLexerComprehensive.dir/build

CMakeFiles/TestLexerComprehensive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestLexerComprehensive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestLexerComprehensive.dir/clean

CMakeFiles/TestLexerComprehensive.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/lexer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/lexer /Users/humgic/Applications/my_compiler/test/lexer /Users/humgic/Applications/my_compiler/test/lexer/build /Users/humgic/Applications/my_compiler/test/lexer/build /Users/humgic/Applications/my_compiler/test/lexer/build/CMakeFiles/TestLexerComprehensive.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestLexerComprehensive.dir/depend

