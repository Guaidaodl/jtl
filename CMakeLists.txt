cmake_minimum_required(VERSION 3.0)

project(jenkins)

set(CMAKE_CXX_STANDARD 17)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_executable(main src/main.cc src/jtl.cc)

target_precompile_headers(main 
  PRIVATE 
    src/pch.h
)
target_link_libraries(main ${CONAN_LIBS})
