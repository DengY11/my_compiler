# Add the test source file (test_token.cpp)
set(TEST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/test_token.cpp)

# Create the executable for the test
add_executable(test_token ${TEST_FILE})

# Link the executable with the token library defined in the root CMakeLists.txt
target_link_libraries(test_token PRIVATE token_lib)

