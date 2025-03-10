cmake_minimum_required(VERSION 3.10)
project(TokenTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

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

# 创建可执行文件并链接静态库
add_executable(TestToken ${TEST_SOURCES})
target_link_libraries(TestToken TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(TestToken)

# 创建测试
add_executable(TestTokenClass test_token_class.cpp)
target_link_libraries(TestTokenClass TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestTokenHelperFunctions test_token_helper_functions.cpp)
target_link_libraries(TestTokenHelperFunctions TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(TestTokenTypes test_token_types.cpp)
target_link_libraries(TestTokenTypes TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 添加新的Token位置测试
add_executable(TestTokenPosition test_token_position.cpp)
target_link_libraries(TestTokenPosition TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 添加新的Token位置综合测试
add_executable(TestTokenPositionComprehensive test_token_position_comprehensive.cpp)
target_link_libraries(TestTokenPositionComprehensive TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

