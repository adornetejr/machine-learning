cmake_minimum_required(VERSION 2.8) 

project(id3)

if (APPLE)
  set(CMAKE_MACOSX_RPATH 1)
endif()

add_executable(id3
  ${CMAKE_SOURCE_DIR}/main.cc
)

if (UNIX)
  target_compile_options(id3 PUBLIC -D_DEBUG -std=c++11 -O0 -g)
endif()