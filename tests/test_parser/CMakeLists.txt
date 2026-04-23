add_executable(test_parser
        "${CMAKE_CURRENT_SOURCE_DIR}/state_normal.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/state_string.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/parser_error_case.cc")

add_toysh_test_target(test_parser)