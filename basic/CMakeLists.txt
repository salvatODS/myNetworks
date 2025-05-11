cmake_minimum_required(3.0)
project(atomics)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_atomic main.cpp)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)