cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main main.cpp src/figures.cpp)

enable_testing()
add_executable(tests test/test.cpp src/figures.cpp)
add_test(NAME AllTests COMMAND tests)