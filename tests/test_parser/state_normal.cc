#include "utils/test_utils.hpp"
#include "gtest/gtest.h"

TEST(ParserTest, StateNoraml) {
    char input[] = "g++ -O3 -std=c++20 --Wall parser.cc -o parser";
    const std::vector<std::string> output = {
        "g++", "-O3", "-std=c++20", "--Wall",
        "parser.cc", "-o", "parser"
    };

    toysh::test::test_parser(input, output);
}