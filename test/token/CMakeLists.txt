cmake_minimum_required(VERSION 3.10)
project(TokenTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/../../include)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 指定测试可执行文件的源文件
set(TEST_SOURCES 
    test_token.cpp
    test_token_types.cpp
    test_token_helper_functions.cpp
    test_token_class.cpp
)

# 添加 token 模块的源文件
file(GLOB TOKEN_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/token/*.cpp")

# 创建静态库
add_library(TokenLib STATIC ${TOKEN_SRC_FILES})

# 创建可执行文件并链接静态库
add_executable(TestToken ${TEST_SOURCES})
target_link_libraries(TestToken TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(TestToken)

