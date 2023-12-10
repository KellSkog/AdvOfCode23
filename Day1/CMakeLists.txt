cmake_minimum_required(VERSION 3.15)
set(CXX_STANDARD C20)
# CMake Error at CMakeLists.txt:8 (target_compile_features):
#   target_compile_features The CXX_STANDARD property on target "day1"
#   contained an invalid value: "C++20".
set(CMAKE_CXX_STANDARD 20)
project(Day1)
add_executable(day1 main.cpp day1.cpp)
#INTERFACE: Not used but exported, PUBLIC: Used and exported and PRIVATE: Used but not exported
#set_property(TARGET day1 PROPERTY CXX_STANDARD 20)
target_compile_features(day1 PUBLIC cxx_std_20)

# Prepare doctest for other targets to use
# find_package(doctest REQUIRED)
add_executable(test_day1    test_day1.cpp
                            day1.cpp)
target_compile_features(test_day1 PRIVATE cxx_std_17)
# target_link_libraries(test_day1 PRIVATE doctest::doctest)