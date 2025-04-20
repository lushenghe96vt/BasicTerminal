#cmake_minimum_required(VERSION 3.10)
# Set the C++ standard to C++23 bruh

#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# used internally by CMake to identify your project
#project(matrix)

# Include the directory headers are located
#include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the main executable
#add_executable(matrix src/main.cpp src/matrix.cpp)


####################################################
# Add the test executable
#add_executable(my_test src/matrix.cpp test/test.cpp)
# Include directories for the test target
#target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
# Enable testing
#enable_testing()
# Register the test executable with CTest (optional)
#add_test(NAME my_test COMMAND my_test)

cmake_minimum_required(VERSION 3.10)
project(Terminal)

# Set C++ Standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/test/catch2)  # Add Catch2 directory

# Main executable
add_executable(Terminal src/main.cpp src/mypipe.cpp src/terminal.cpp src/utility.cpp)

#####################################################################################################
# Catch2 Test Setup
#####################################################################################################

# Add test executable
add_executable(my_test test/test.cpp src/mypipe.cpp src/terminal.cpp src/utility.cpp test/catch2/catch_amalgamated.cpp)

# Ensure the test executable has access to headers
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/test/catch2)

# Enable testing
enable_testing()

# Register test with CTest
add_test(NAME my_test COMMAND my_test)