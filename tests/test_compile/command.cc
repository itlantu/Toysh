#include "toysh/command.h"
#include "utils/test_utils.hpp"
#include "gtest/gtest.h"

int test_func(int argc, char** argv) {
    return 0;
}
TOYSH_EXPORT_COMMAND("test_func", "test_func", test_func);

TEST(CompileTest, Command) {
    ASSERT_NE(toysh_get_command_count(), 0);

    const ToyshCommand* cmd = toysh_find_command("test_func");
    ASSERT_NE(cmd, nullptr);
    EXPECT_STREQ(cmd->name, "test_func");
    EXPECT_STREQ(cmd->help, "test_func");
    EXPECT_EQ(cmd->func, test_func);
}
