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

if(${TOYSH_ENABLE_LINT})
    find_package(Python3 REQUIRED)

    add_custom_target(lint
        COMMAND ${Python3_EXECUTABLE} -m cpplint
            --quiet
            --recursive
            --filter=-legal/copyright,-build/header_guard,-build/include_what_you_use
            --linelength=120
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "[toysh] 尝试调用cpplint进行代码规范检查"
    )

    add_dependencies(libtoysh lint)
endif()

if(${TOYSH_ENABLE_TEST})
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()

if(${MSVC})
    add_compile_options(utf-8)
endif ()