cmake_minimum_required(VERSION 3.15)

project(cache_list)

#git rm --cached .vscode

if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "In-source build is forbidden")
endif()

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -Wall -Wextra")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX .)
endif()

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)
