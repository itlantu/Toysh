cmake_minimum_required(VERSION 3.25)
project(toysh LANGUAGES C)

option(TOYSH_ENABLE_TEST OFF)
option(TOYSH_ENABLE_LINT OFF)

set(CMAKE_C_STANDARD                17)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

file(GLOB TOYSH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
set(TOYSH_INCLUDE_DIRS  "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(libtoysh STATIC ${TOYSH_SOURCES})
target_include_directories(libtoysh PRIVATE ${TOYSH_INCLUDE_DIRS})

if(${TOYSH_ENABLE_TEST})
    message(STATUS "[toysh] 尝试启动测试")
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
    message(STATUS "[toysh] 测试完成")
endif()
