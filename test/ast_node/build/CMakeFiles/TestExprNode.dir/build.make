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
include CMakeFiles/TestExprNode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestExprNode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestExprNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestExprNode.dir/flags.make

CMakeFiles/TestExprNode.dir/codegen:
.PHONY : CMakeFiles/TestExprNode.dir/codegen

CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o: CMakeFiles/TestExprNode.dir/flags.make
CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o: /Users/humgic/Applications/my_compiler/test/ast_node/test_expr_node.cpp
CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o: CMakeFiles/TestExprNode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o -MF CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o.d -o CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o -c /Users/humgic/Applications/my_compiler/test/ast_node/test_expr_node.cpp

CMakeFiles/TestExprNode.dir/test_expr_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestExprNode.dir/test_expr_node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/ast_node/test_expr_node.cpp > CMakeFiles/TestExprNode.dir/test_expr_node.cpp.i

CMakeFiles/TestExprNode.dir/test_expr_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestExprNode.dir/test_expr_node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/ast_node/test_expr_node.cpp -o CMakeFiles/TestExprNode.dir/test_expr_node.cpp.s

# Object files for target TestExprNode
TestExprNode_OBJECTS = \
"CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o"

# External object files for target TestExprNode
TestExprNode_EXTERNAL_OBJECTS =

TestExprNode: CMakeFiles/TestExprNode.dir/test_expr_node.cpp.o
TestExprNode: CMakeFiles/TestExprNode.dir/build.make
TestExprNode: libASTNodeLib.a
TestExprNode: libLexerLib.a
TestExprNode: libTokenLib.a
TestExprNode: /opt/homebrew/lib/libgtest.a
TestExprNode: /opt/homebrew/lib/libgtest_main.a
TestExprNode: /opt/homebrew/lib/libgtest.a
TestExprNode: CMakeFiles/TestExprNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestExprNode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestExprNode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestExprNode.dir/build: TestExprNode
.PHONY : CMakeFiles/TestExprNode.dir/build

CMakeFiles/TestExprNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestExprNode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestExprNode.dir/clean

CMakeFiles/TestExprNode.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/ast_node/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles/TestExprNode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestExprNode.dir/depend

