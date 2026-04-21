add_executable(test_parser
        "${CMAKE_CURRENT_SOURCE_DIR}/state_normal.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/state_string.cc")

add_toysh_test_target(test_parser)