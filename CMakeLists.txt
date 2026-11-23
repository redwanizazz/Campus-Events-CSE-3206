cmake_minimum_required(VERSION 3.14)
project(CampusEvents)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test and Google Mock
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the test executable
add_executable(booking_test tests/booking_test.cpp)

# Link Google Test, Google Mock, and threading library to the executable
target_link_libraries(booking_test gtest gmock gtest_main pthread)