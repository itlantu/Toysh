#include "test_utils.hpp"
#include <cstring>
#include <iostream>

#include "gtest/gtest.h"
#include "toysh/parser.h"

void toysh::test::test_parser(const std::string& input, const std::vector<std::string>& output) {
    const auto size = input.size();
    auto input_c_str = new char[size + 1];

    strcpy_s(input_c_str, sizeof(char) * size, input.c_str());
    input_c_str[size] = '\0';
    test_parser(input_c_str, output);

    delete[] input_c_str;
}

void toysh::test::test_parser(char* input_c_str, const std::vector<std::string>& output) {
    const int n = static_cast<int>(output.size()) + 1;
    auto argv = new char*[n];
    int argc = 0;

    ASSERT_EQ(toysh_parser(input_c_str, &argc, argv, n), TOYSH_OK);
    EXPECT_EQ(argc, output.size());

    const int m = std::min(n, static_cast<int>(output.size()));
    for (int i = 0; i < m; ++i) {
        EXPECT_STREQ(argv[i], output[i].c_str());
    }

    delete[] argv;
}