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
include CMakeFiles/TestVarDeclNode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestVarDeclNode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestVarDeclNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestVarDeclNode.dir/flags.make

CMakeFiles/TestVarDeclNode.dir/codegen:
.PHONY : CMakeFiles/TestVarDeclNode.dir/codegen

CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o: CMakeFiles/TestVarDeclNode.dir/flags.make
CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o: /Users/humgic/Applications/my_compiler/test/ast_node/test_var_decl_node.cpp
CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o: CMakeFiles/TestVarDeclNode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o -MF CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o.d -o CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o -c /Users/humgic/Applications/my_compiler/test/ast_node/test_var_decl_node.cpp

CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/ast_node/test_var_decl_node.cpp > CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.i

CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/ast_node/test_var_decl_node.cpp -o CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.s

# Object files for target TestVarDeclNode
TestVarDeclNode_OBJECTS = \
"CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o"

# External object files for target TestVarDeclNode
TestVarDeclNode_EXTERNAL_OBJECTS =

TestVarDeclNode: CMakeFiles/TestVarDeclNode.dir/test_var_decl_node.cpp.o
TestVarDeclNode: CMakeFiles/TestVarDeclNode.dir/build.make
TestVarDeclNode: libASTNodeLib.a
TestVarDeclNode: libLexerLib.a
TestVarDeclNode: libTokenLib.a
TestVarDeclNode: /opt/homebrew/lib/libgtest.a
TestVarDeclNode: /opt/homebrew/lib/libgtest_main.a
TestVarDeclNode: /opt/homebrew/lib/libgtest.a
TestVarDeclNode: CMakeFiles/TestVarDeclNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestVarDeclNode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestVarDeclNode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestVarDeclNode.dir/build: TestVarDeclNode
.PHONY : CMakeFiles/TestVarDeclNode.dir/build

CMakeFiles/TestVarDeclNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestVarDeclNode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestVarDeclNode.dir/clean

CMakeFiles/TestVarDeclNode.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/ast_node/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build /Users/humgic/Applications/my_compiler/test/ast_node/build/CMakeFiles/TestVarDeclNode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestVarDeclNode.dir/depend

