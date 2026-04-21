#include "utils/test_utils.hpp"
#include "gtest/gtest.h"

TEST(ParserTest, StateString_0) {
    char input[] = R"(echo "hello world" '123')";
    const std::vector<std::string> output = {
        "echo", "hello world", "'123'"
    };

    toysh::test::test_parser(input, output);
}

TEST(ParserTest, StateString_1) {
    char input[] = R"(echo "hello \"world\"\n" )";
    const std::vector<std::string> output = {
        "echo", "hello \"world\"\n",
    };

    toysh::test::test_parser(input, output);
}