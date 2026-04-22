add_executable(test_compile
        "${CMAKE_CURRENT_SOURCE_DIR}/parser.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/command.cc")

add_toysh_test_target(test_compile)