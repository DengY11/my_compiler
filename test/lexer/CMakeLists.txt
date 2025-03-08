cmake_minimum_required(VERSION 3.10)
project(LexerTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/../../include)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加 token 模块的源文件
file(GLOB TOKEN_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/token/*.cpp")

# 添加 lexer 模块的源文件
file(GLOB LEXER_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/lexer/*.cpp")

# 创建token静态库
add_library(TokenLib STATIC ${TOKEN_SRC_FILES})

# 创建lexer静态库
add_library(LexerLib STATIC ${LEXER_SRC_FILES})
target_link_libraries(LexerLib TokenLib)

# 创建可执行文件并链接静态库
add_executable(TestSeparator test_separator.cpp)
target_link_libraries(TestSeparator LexerLib TokenLib)

# 创建可执行文件并链接静态库
add_executable(TestLexerDebug test_lexer_debug.cpp)
target_link_libraries(TestLexerDebug LexerLib TokenLib)

# 创建可执行文件并链接静态库
add_executable(TestLexer test_lexer_separator.cpp)
target_link_libraries(TestLexer LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建可执行文件并链接静态库
add_executable(TestLexerComprehensive test_lexer_comprehensive.cpp)
target_link_libraries(TestLexerComprehensive LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread) 