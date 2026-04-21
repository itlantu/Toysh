#ifndef TOYSH_TESTS_UTILS_H
#define TOYSH_TESTS_UTILS_H

#include <vector>
#include <string>

namespace toysh::test{

void test_parser(const std::string& input, const std::vector<std::string>& output);
void test_parser(char* input_c_str, const std::vector<std::string>& output);

}  // toysh::test

#endif  // TOYSH_TESTS_UTILS_H
