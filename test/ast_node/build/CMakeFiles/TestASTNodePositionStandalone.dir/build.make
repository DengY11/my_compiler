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
CMAKE_SOURCE_DIR = /Users/humgic/Applications/my_compiler/test/ast_node

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/humgic/Applications/my_compiler/test/ast_node/build

# Include any dependencies generated for this target.
include CMakeFiles/TestASTNodePositionStandalone.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestASTNodePositionStandalone.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestASTNodePositionStandalone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestASTNodePositionStandalone.dir/flags.make

CMakeFiles/TestASTNodePositionStandalone.dir/codegen:
.PHONY : CMakeFiles/TestASTNodePositionStandalone.dir/codegen

CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o: CMakeFiles/TestASTNodePositionStandalone.dir/flags.make
CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o: /Users/humgic/Applications/my_compiler/test/ast_node/test_ast_node_position_standalone.cpp
CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o: CMakeFiles/TestASTNodePositionStandalone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o -MF CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o.d -o CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o -c /Users/humgic/Applications/my_compiler/test/ast_node/test_ast_node_position_standalone.cpp

CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/ast_node/test_ast_node_position_standalone.cpp > CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.i

CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/ast_node/test_ast_node_position_standalone.cpp -o CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.s

# Object files for target TestASTNodePositionStandalone
TestASTNodePositionStandalone_OBJECTS = \
"CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o"

# External object files for target TestASTNodePositionStandalone
TestASTNodePositionStandalone_EXTERNAL_OBJECTS =

TestASTNodePositionStandalone: CMakeFiles/TestASTNodePositionStandalone.dir/test_ast_node_position_standalone.cpp.o
TestASTNodePositionStandalone: CMakeFiles/TestASTNodePositionStandalone.dir/build.make
TestASTNodePositionStandalone: libLexerLib.a
TestASTNodePositionStandalone: libTokenLib.a
TestASTNodePositionStandalone: /opt/homebrew/lib/libgtest.a
TestASTNodePositionStandalone: /opt/homebrew/lib/libgtest_main.a
TestASTNodePositionStandalone: /opt/homebrew/lib/libgtest.a
TestASTNodePositionStandalone: CMakeFiles/TestASTNodePositionStandalone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestASTNodePositionStandalone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestASTNodePositionStandalone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestASTNodePositionStandalone.dir/build: TestASTNodePositionStandalone
.PHONY : CMakeFiles/TestASTNodePositionStandalone.dir/build

CMakeFiles/TestASTNodePositionStandalone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestASTNodePositionStandalone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestASTNodePositionStandalone.dir/clean

CMakeFiles/TestASTNodePositionStandalone.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/ast_node/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles/TestASTNodePositionStandalone.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestASTNodePositionStandalone.dir/depend

