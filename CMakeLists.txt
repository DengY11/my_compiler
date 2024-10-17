# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project
project(my_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add all source files from src/token
file(GLOB TOKEN_SRC
    ${CMAKE_SOURCE_DIR}/src/token/*.cpp
)

# Define the library for token module
add_library(token_lib ${TOKEN_SRC})

# Add the subdirectory for unit tests
add_subdirectory(test/token)

