#include <string>
#include <cstring>
#include "gtest/gtest.h"

#include "toysh/parser.h"
#include "utils/test_utils.hpp"

TEST(ParserTest, ArrayIndexOver) {
    const std::string input = "echo hello world";
    char* argv[32];

    for (int i = 0; i < 3; ++i) {
        char* input_c_str = new char[input.size() + 1];
        strcpy_s(input_c_str, input.size() + 1, input.c_str());
        input_c_str[input.size()] = '\0';

        int argc = 0;
        const auto result = toysh_parser(input_c_str, &argc, argv, i);
        ASSERT_EQ(result, TOYSH_ERR_INDEX_OVER);
        delete[] input_c_str;
    }
}