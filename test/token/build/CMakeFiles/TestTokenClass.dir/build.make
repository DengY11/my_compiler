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
CMAKE_SOURCE_DIR = /Users/humgic/Applications/my_compiler/test/token

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/humgic/Applications/my_compiler/test/token/build

# Include any dependencies generated for this target.
include CMakeFiles/TestTokenClass.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestTokenClass.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestTokenClass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestTokenClass.dir/flags.make

CMakeFiles/TestTokenClass.dir/codegen:
.PHONY : CMakeFiles/TestTokenClass.dir/codegen

CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o: CMakeFiles/TestTokenClass.dir/flags.make
CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o: /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp
CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o: CMakeFiles/TestTokenClass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o -MF CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o.d -o CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o -c /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp

CMakeFiles/TestTokenClass.dir/test_token_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestTokenClass.dir/test_token_class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp > CMakeFiles/TestTokenClass.dir/test_token_class.cpp.i

CMakeFiles/TestTokenClass.dir/test_token_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestTokenClass.dir/test_token_class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp -o CMakeFiles/TestTokenClass.dir/test_token_class.cpp.s

# Object files for target TestTokenClass
TestTokenClass_OBJECTS = \
"CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o"

# External object files for target TestTokenClass
TestTokenClass_EXTERNAL_OBJECTS =

TestTokenClass: CMakeFiles/TestTokenClass.dir/test_token_class.cpp.o
TestTokenClass: CMakeFiles/TestTokenClass.dir/build.make
TestTokenClass: libTokenLib.a
TestTokenClass: /opt/homebrew/lib/libgtest.a
TestTokenClass: /opt/homebrew/lib/libgtest_main.a
TestTokenClass: /opt/homebrew/lib/libgtest.a
TestTokenClass: CMakeFiles/TestTokenClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestTokenClass"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestTokenClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestTokenClass.dir/build: TestTokenClass
.PHONY : CMakeFiles/TestTokenClass.dir/build

CMakeFiles/TestTokenClass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestTokenClass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestTokenClass.dir/clean

CMakeFiles/TestTokenClass.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/token/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/token /Users/humgic/Applications/my_compiler/test/token /Users/humgic/Applications/my_compiler/test/token/build /Users/humgic/Applications/my_compiler/test/token/build /Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles/TestTokenClass.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestTokenClass.dir/depend

