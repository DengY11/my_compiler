cmake_minimum_required(VERSION 3.10)
project(FileReaderTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/../../include)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加 file_reader 模块的源文件
file(GLOB FILE_READER_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/file_reader/*.cpp")

# 创建file_reader静态库
add_library(FileReaderLib STATIC ${FILE_READER_SRC_FILES})

# 创建测试
add_executable(TestFileReader test_file_reader.cpp)
target_link_libraries(TestFileReader FileReaderLib ${GTEST_BOTH_LIBRARIES} pthread) 