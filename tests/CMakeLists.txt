
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE qbech32)
add_test(NAME tests COMMAND tests)



