CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
project(ToyshTest)

set(CMAKE_CXX_STANDARD  20)
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/third_party")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  "https://gitclone.com/github.com/google/googletest"
#    GIT_REPOSITORY  "https://github.com/google/googletest"
    GIT_TAG         "v1.17.0"
    GIT_PROGRESS    TRUE
    GIT_SHALLOW     TRUE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_library(libtoysh_test_utils STATIC
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/test_parser.cc")
target_include_directories(libtoysh_test_utils PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        ${TOYSH_INCLUDE_DIRS})
target_link_libraries(libtoysh_test_utils PUBLIC
        libtoysh
        GTest::gtest
        GTest::gtest_main)

function(add_toysh_test_target target)
    target_link_libraries(${target} PRIVATE libtoysh_test_utils)
    gtest_discover_tests(${target})
endfunction()

if(${MSVC})
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(test_compile)
add_subdirectory(test_parser)
