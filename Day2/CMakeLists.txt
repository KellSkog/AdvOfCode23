add_executable(day2 main.cpp day2.cpp)
#INTERFACE: Not used but exported, PUBLIC: Used and exported and PRIVATE: Used but not exported
#set_property(TARGET day1 PROPERTY CXX_STANDARD 20)
target_compile_features(day2 PUBLIC cxx_std_20)

# Prepare doctest for other targets to use

add_executable(test_day2    test_day2.cpp
                            day2.cpp)
target_compile_features(test_day2 PUBLIC cxx_std_20)
# CMake Error at Day2/CMakeLists.txt:4 (target_compile_features):
# Cannot specify compile features for target "day2" which is not built by
# this project.
# target_compile_features(test_day2 PRIVATE cxx_std_17)
# target_link_libraries(test_day2 PRIVATE doctest::doctest)