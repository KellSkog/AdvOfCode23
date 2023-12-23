add_executable(dayxx main.cpp dayxx.cpp)
#INTERFACE: Not used but exported, PUBLIC: Used and exported and PRIVATE: Used but not exported

target_compile_features(dayxx PUBLIC cxx_std_20)

add_executable(test_dayxx    test_dayxx.cpp
                            dayxx.cpp)
target_compile_features(test_dayxx PUBLIC cxx_std_20)