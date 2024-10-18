# 查找测试代码的源文件
file(GLOB TEST_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/test/lexer/*.cpp
)

# 编译测试可执行文件
add_executable(TestLexer ${TEST_SOURCE_FILES})

# 链接静态库 MyCompilerLib
target_link_libraries(TestLexer MyCompilerLib)

set(CMAKE_BUILD_TYPE Debug)

