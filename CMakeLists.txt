
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(neetcode)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directory for the executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/src/)

# Add static libraries needed for other executables
add_library(definitions STATIC src/definitions.cpp)

# Add executables and their corresponding source and header files
add_executable(anagram.out src/anagram.cpp)
add_executable(contains_duplicate.out src/contains_duplicate.cpp)
add_executable(merge_two_sorted.out src/merge_two_sorted.cpp)
add_executable(two_integer_sum.out src/two_integer_sum.cpp)
add_executable(reverse_linked_list.out src/reverse_linked_list.cpp)

# Link the static library to the executables that need it
target_link_libraries(merge_two_sorted.out definitions)
target_link_libraries(reverse_linked_list.out definitions)
