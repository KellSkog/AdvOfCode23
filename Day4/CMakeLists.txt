add_executable(day4 main.cpp day4.cpp)
#INTERFACE: Not used but exported, PUBLIC: Used and exported and PRIVATE: Used but not exported

target_compile_features(day4 PUBLIC cxx_std_20)

add_executable(test_day4    test_day4.cpp
                            day4.cpp)
target_compile_features(test_day4 PUBLIC cxx_std_20)
