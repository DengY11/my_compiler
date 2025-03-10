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
include CMakeFiles/TestBinaryExprNode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestBinaryExprNode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestBinaryExprNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestBinaryExprNode.dir/flags.make

CMakeFiles/TestBinaryExprNode.dir/codegen:
.PHONY : CMakeFiles/TestBinaryExprNode.dir/codegen

CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o: CMakeFiles/TestBinaryExprNode.dir/flags.make
CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o: /Users/humgic/Applications/my_compiler/test/ast_node/test_binary_expr_node.cpp
CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o: CMakeFiles/TestBinaryExprNode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o -MF CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o.d -o CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o -c /Users/humgic/Applications/my_compiler/test/ast_node/test_binary_expr_node.cpp

CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/ast_node/test_binary_expr_node.cpp > CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.i

CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/ast_node/test_binary_expr_node.cpp -o CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.s

# Object files for target TestBinaryExprNode
TestBinaryExprNode_OBJECTS = \
"CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o"

# External object files for target TestBinaryExprNode
TestBinaryExprNode_EXTERNAL_OBJECTS =

TestBinaryExprNode: CMakeFiles/TestBinaryExprNode.dir/test_binary_expr_node.cpp.o
TestBinaryExprNode: CMakeFiles/TestBinaryExprNode.dir/build.make
TestBinaryExprNode: libASTNodeLib.a
TestBinaryExprNode: libLexerLib.a
TestBinaryExprNode: libTokenLib.a
TestBinaryExprNode: /opt/homebrew/lib/libgtest.a
TestBinaryExprNode: /opt/homebrew/lib/libgtest_main.a
TestBinaryExprNode: /opt/homebrew/lib/libgtest.a
TestBinaryExprNode: CMakeFiles/TestBinaryExprNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestBinaryExprNode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestBinaryExprNode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestBinaryExprNode.dir/build: TestBinaryExprNode
.PHONY : CMakeFiles/TestBinaryExprNode.dir/build

CMakeFiles/TestBinaryExprNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestBinaryExprNode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestBinaryExprNode.dir/clean

CMakeFiles/TestBinaryExprNode.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/ast_node/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles/TestBinaryExprNode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestBinaryExprNode.dir/depend

