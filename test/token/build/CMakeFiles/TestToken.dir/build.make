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
include CMakeFiles/TestToken.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestToken.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestToken.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestToken.dir/flags.make

CMakeFiles/TestToken.dir/codegen:
.PHONY : CMakeFiles/TestToken.dir/codegen

CMakeFiles/TestToken.dir/test_token.cpp.o: CMakeFiles/TestToken.dir/flags.make
CMakeFiles/TestToken.dir/test_token.cpp.o: /Users/humgic/Applications/my_compiler/test/token/test_token.cpp
CMakeFiles/TestToken.dir/test_token.cpp.o: CMakeFiles/TestToken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestToken.dir/test_token.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestToken.dir/test_token.cpp.o -MF CMakeFiles/TestToken.dir/test_token.cpp.o.d -o CMakeFiles/TestToken.dir/test_token.cpp.o -c /Users/humgic/Applications/my_compiler/test/token/test_token.cpp

CMakeFiles/TestToken.dir/test_token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestToken.dir/test_token.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/token/test_token.cpp > CMakeFiles/TestToken.dir/test_token.cpp.i

CMakeFiles/TestToken.dir/test_token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestToken.dir/test_token.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/token/test_token.cpp -o CMakeFiles/TestToken.dir/test_token.cpp.s

CMakeFiles/TestToken.dir/test_token_types.cpp.o: CMakeFiles/TestToken.dir/flags.make
CMakeFiles/TestToken.dir/test_token_types.cpp.o: /Users/humgic/Applications/my_compiler/test/token/test_token_types.cpp
CMakeFiles/TestToken.dir/test_token_types.cpp.o: CMakeFiles/TestToken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestToken.dir/test_token_types.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestToken.dir/test_token_types.cpp.o -MF CMakeFiles/TestToken.dir/test_token_types.cpp.o.d -o CMakeFiles/TestToken.dir/test_token_types.cpp.o -c /Users/humgic/Applications/my_compiler/test/token/test_token_types.cpp

CMakeFiles/TestToken.dir/test_token_types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestToken.dir/test_token_types.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/token/test_token_types.cpp > CMakeFiles/TestToken.dir/test_token_types.cpp.i

CMakeFiles/TestToken.dir/test_token_types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestToken.dir/test_token_types.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/token/test_token_types.cpp -o CMakeFiles/TestToken.dir/test_token_types.cpp.s

CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o: CMakeFiles/TestToken.dir/flags.make
CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o: /Users/humgic/Applications/my_compiler/test/token/test_token_helper_functions.cpp
CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o: CMakeFiles/TestToken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o -MF CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o.d -o CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o -c /Users/humgic/Applications/my_compiler/test/token/test_token_helper_functions.cpp

CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/token/test_token_helper_functions.cpp > CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.i

CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/token/test_token_helper_functions.cpp -o CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.s

CMakeFiles/TestToken.dir/test_token_class.cpp.o: CMakeFiles/TestToken.dir/flags.make
CMakeFiles/TestToken.dir/test_token_class.cpp.o: /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp
CMakeFiles/TestToken.dir/test_token_class.cpp.o: CMakeFiles/TestToken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TestToken.dir/test_token_class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestToken.dir/test_token_class.cpp.o -MF CMakeFiles/TestToken.dir/test_token_class.cpp.o.d -o CMakeFiles/TestToken.dir/test_token_class.cpp.o -c /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp

CMakeFiles/TestToken.dir/test_token_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestToken.dir/test_token_class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp > CMakeFiles/TestToken.dir/test_token_class.cpp.i

CMakeFiles/TestToken.dir/test_token_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestToken.dir/test_token_class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/humgic/Applications/my_compiler/test/token/test_token_class.cpp -o CMakeFiles/TestToken.dir/test_token_class.cpp.s

# Object files for target TestToken
TestToken_OBJECTS = \
"CMakeFiles/TestToken.dir/test_token.cpp.o" \
"CMakeFiles/TestToken.dir/test_token_types.cpp.o" \
"CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o" \
"CMakeFiles/TestToken.dir/test_token_class.cpp.o"

# External object files for target TestToken
TestToken_EXTERNAL_OBJECTS =

TestToken: CMakeFiles/TestToken.dir/test_token.cpp.o
TestToken: CMakeFiles/TestToken.dir/test_token_types.cpp.o
TestToken: CMakeFiles/TestToken.dir/test_token_helper_functions.cpp.o
TestToken: CMakeFiles/TestToken.dir/test_token_class.cpp.o
TestToken: CMakeFiles/TestToken.dir/build.make
TestToken: libTokenLib.a
TestToken: /opt/homebrew/lib/libgtest.a
TestToken: /opt/homebrew/lib/libgtest_main.a
TestToken: /opt/homebrew/lib/libgtest.a
TestToken: CMakeFiles/TestToken.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TestToken"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestToken.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/bin/cmake -D TEST_TARGET=TestToken -D TEST_EXECUTABLE=/Users/humgic/Applications/my_compiler/test/token/build/TestToken -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/humgic/Applications/my_compiler/test/token/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=TestToken_TESTS -D CTEST_FILE=/Users/humgic/Applications/my_compiler/test/token/build/TestToken[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_DISCOVERY_EXTRA_ARGS= -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/TestToken.dir/build: TestToken
.PHONY : CMakeFiles/TestToken.dir/build

CMakeFiles/TestToken.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestToken.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestToken.dir/clean

CMakeFiles/TestToken.dir/depend:
	cd /Users/humgic/Applications/my_compiler/test/token/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/humgic/Applications/my_compiler/test/token /Users/humgic/Applications/my_compiler/test/token /Users/humgic/Applications/my_compiler/test/token/build /Users/humgic/Applications/my_compiler/test/token/build /Users/humgic/Applications/my_compiler/test/token/build/CMakeFiles/TestToken.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestToken.dir/depend

