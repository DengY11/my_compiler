# 指定测试可执行文件的源文件
set(TEST_SOURCES test_lexer.cpp)

# 创建可执行文件并链接静态库
add_executable(TestLexer ${TEST_SOURCES})
target_link_libraries(TestLexer MyCompilerLib)

