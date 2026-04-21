cmake_minimum_required(VERSION 3.25)
project(toysh LANGUAGES C)

option(TOYSH_ENABLE_TEST OFF)

set(CMAKE_C_STANDARD    17)

file(GLOB TOYSH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
set(TOYSH_INCLUDE_DIRS  "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(libtoysh STATIC ${TOYSH_SOURCES})
target_include_directories(libtoysh PRIVATE ${TOYSH_INCLUDE_DIRS})

if (${TOYSH_ENABLE_TEST})
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif ()

