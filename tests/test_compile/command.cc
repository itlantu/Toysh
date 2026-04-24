#include <vector>
#include <string>
#include <iostream>

#include "gtest/gtest.h"
#include "toysh/command.h"
#include "utils/test_utils.hpp"
#include <cstdio>

int test_func1(int argc, char** argv) {
    return 0;
}

int test_func2(int argc, char** argv) {
    return 0;
}

TOYSH_CMD_EXPORT(test1, test_func1, "test_func1");
TOYSH_CMD_EXPORT(test2, test_func2, "test_func2");

TEST(CompileTest, Command) {
    ASSERT_EQ(TOYSH_COMMAND_SECTION_BEGIN(), toysh_command_section_begin());
    ASSERT_EQ(TOYSH_COMMAND_SECTION_END(), toysh_command_section_end());
}
