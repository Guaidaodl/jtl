cmake_minimum_required(VERSION 3.0)

project(jenkins)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(main src/main.cc src/jtl.cc)

target_precompile_headers(main 
  PRIVATE 
    src/pch.h
)
target_link_libraries(main ${CONAN_LIBS})
