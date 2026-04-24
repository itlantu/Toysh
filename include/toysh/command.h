#ifndef TOYSH_COMMAND_H
#define TOYSH_COMMAND_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef int (*ToyshFunc)(int argc, char** argv);

struct ToyshCommand {
    const char* name;
    const char* desc;
    ToyshFunc func;
};

extern const struct ToyshCommand __start_toysh;
extern const struct ToyshCommand __stop_toysh;

#ifdef _MSC_VER
#pragma section(".rdata$toysh$a", read)
#pragma section(".rdata$toysh$m", read)
#pragma section(".rdata$toysh$z", read)
#define TOYSH_COMMAND_INIT()    \
    __declspec(allocate(".rdata$toysh$a"))  \
    const struct ToyshCommand __start_toysh = {"__start", "begin of section", NULL};    \
    __declspec(allocate(".rdata$toysh$z"))  \
    const struct ToyshCommand __stop_toysh = {"__stop", "end of section", NULL}
#else
#define TOYSH_COMMAND_INIT()
#endif

#if defined(_MSC_VER)
#define TOYSH_CMD_EXPORT(name, func, desc)  \
    const char __toysh_cmd_name_##name[] = #name;   \
    const char __toysh_cmd_desc_##name[] = desc;    \
    __declspec(allocate(".rdata$toysh$m"))  \
    const struct ToyshCommand __toysh_cmd_object##name = {#name, desc, func};
#else
// todo
#endif

#define TOYSH_COMMAND_SECTION_BEGIN()  ((const struct ToyshCommand*)&__start_toysh)
#define TOYSH_COMMAND_SECTION_END()    ((const struct ToyshCommand*)&__stop_toysh)

const struct ToyshCommand* toysh_command_section_begin();
const struct ToyshCommand* toysh_command_section_end();

unsigned int toysh_command_get_count();
const struct ToyshCommand* toysh_command_find(const char* name);

#ifdef __cplusplus
}
#endif

#endif  /* TOYSH_COMMAND_H */
