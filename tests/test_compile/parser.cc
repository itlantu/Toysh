#include "utils/test_utils.hpp"
#include "gtest/gtest.h"

TEST(CompileTest, Parser) {
    char input[] = "echo \"hello world!\"";
    const std::vector<std::string> output = {
        "echo",
        "hello world!"
    };

    toysh::test::test_parser(input, output);
}
