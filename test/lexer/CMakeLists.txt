cmake_minimum_required(VERSION 3.10)
project(LexerTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 创建测试
add_executable(TestLexer test_lexer.cpp)
target_link_libraries(TestLexer LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestLexerSimple test_lexer_simple.cpp)
target_link_libraries(TestLexerSimple LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestLexerDebug test_lexer_debug.cpp)
target_link_libraries(TestLexerDebug LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestLexerComprehensive test_lexer_comprehensive.cpp)
target_link_libraries(TestLexerComprehensive LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestLexerSeparator test_lexer_separator.cpp)
target_link_libraries(TestLexerSeparator LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 添加新的Lexer位置测试
add_executable(TestLexerPosition test_lexer_position.cpp)
target_link_libraries(TestLexerPosition LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 添加新的Lexer位置综合测试
add_executable(TestLexerPositionComprehensive test_lexer_position_comprehensive.cpp)
target_link_libraries(TestLexerPositionComprehensive LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 添加新的Lexer注释测试
add_executable(TestLexerComment test_lexer_comment.cpp)
target_link_libraries(TestLexerComment LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread) 