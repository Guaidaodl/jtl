cmake_minimum_required(VERSION 3.0)

project(jenkins)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(main src/main.cpp)

target_link_libraries(main ${CONAN_LIBS})
