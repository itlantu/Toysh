#ifndef TOYSH_PARSER_H
#define TOYSH_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#include "toysh/state.h"

ToyshState toysh_parser(char* input, int* argc, char** argv, int argv_size);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // TOYSH_PARSER_H
