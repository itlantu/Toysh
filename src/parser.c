#include "toysh/parser.h"
#include <stddef.h>
#include <ctype.h>

enum ParserState{
    PARSER_START,
    PARSER_NORMAL,
    PARSER_STRING,
    PARSER_STRING_ESCAPE,
};

int argv_push(char** argv, const int argv_size, int* index, char* value) {
    if (*index >= argv_size)
        return -1;
    argv[*index] = value;
    *index += 1;
    return 0;
}

#define ESCAPE_KV() \
    X('r', '\r') \
    X('n', '\n') \
    X('t', '\t') \
    X('"', '\"')

#define X(key, value) key,
static const char escape_keys[] = {ESCAPE_KV()};
#undef X

#define X(key, value) value,
static const char escape_values[] = {ESCAPE_KV()};
#undef X

const unsigned int escape_kv_length = sizeof(escape_keys) / sizeof(const char);

ToyshState toysh_parser(char* input, int* argc, char** argv, const int argv_size) {
    if (input == NULL)
        return TOYSH_ERR_ARG_1_NULL;
    if (argv == NULL)
        return TOYSH_ERR_ARG_2_NULL;
    if (argc == NULL)
        return TOYSH_ERR_ARG_3_NULL;

    enum ParserState parser_state = PARSER_START;
    unsigned int str_offset = 0, start_index = 0;
    char ch;
    *argc = 0;

    for (unsigned int i = 0; (ch = input[i]) != '\0'; ++i) {
        switch (parser_state) {
            case PARSER_START:
                if (isspace(ch))
                    break;
                start_index = i;
                parser_state = ch == '"' ? PARSER_STRING : PARSER_NORMAL;
            break;
            case PARSER_NORMAL:
                if (!isspace(ch))
                    break;
                input[i] = '\0';
                argv_push(argv, argv_size, argc, &input[start_index]);
                parser_state = PARSER_START;
            break;
            case PARSER_STRING:
                if (ch == '"') {
                    input[i - str_offset] = '\0';
                    argv_push(argv, argv_size, argc, &input[start_index + 1]);
                    str_offset = 0;
                    parser_state = PARSER_START;
                    continue;
                }
                if (ch == '\\') {
                    parser_state = PARSER_STRING_ESCAPE;
                    break;
                }
                input[i - str_offset] = ch;
            break;
            case PARSER_STRING_ESCAPE:
                int l = 0;
                for (; l < escape_kv_length; ++l) {
                    if (ch == escape_keys[l])
                        break;
                }
                if (l == escape_kv_length) {
                    --i;
                } else {
                    str_offset += 1;
                    input[i - str_offset] = escape_values[l];
                }
                parser_state = PARSER_STRING;
            break;
        }
    }
    if (parser_state != PARSER_START)
        argv_push(argv, argv_size, argc, &input[start_index]);
    return TOYSH_OK;
}
