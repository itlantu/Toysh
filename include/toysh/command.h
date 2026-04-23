#ifndef TOYSH_COMMAND_H
#define TOYSH_COMMAND_H

#ifdef __cplusplus
extern "C" {
#endif  //  __cplusplus

#include <stdint.h>

typedef int (*ToyshFunc)(int argc, char** argv);

typedef struct ToyshCommand {
    const char* name;
    const char* help;
    ToyshFunc func;
}ToyshCommand;

#if defined(_MSC_VER) && !defined(__clang__)

#pragma section("toysh_section$a", read)
#pragma section("toysh_section$b", read)
#pragma section("toysh_section$c", read)
__declspec(allocate("toysh_section$a"))
static const ToyshCommand* __start_toysh_section = NULL;
__declspec(allocate("toysh_section$c"))
static const ToyshCommand* __stop_toysh_section = NULL;
#define TOYSH_EXPORT_COMMAND(name, help, func) \
    static const ToyshCommand _toysh_cmd ## __COUNTER__ = {name, help, func};\
    const __declspec(allocate("toysh_section$b")) \
    static const ToyshCommand* _toysh_ptr ## __COUNTER__ = &_toysh_cmd ## __COUNTER__
#define TOYSH_SECTION_BEGIN()   ((const ToyshCommand**)(&__start_toysh_section + 1))
#define TOYSH_SECTION_END()     ((const ToyshCommand**)(&__stop_toysh_section))

#else

#define TOYSH_EXPORT_COMMAND(name, help, func) \
    static ToyshCommand _toysh_cmd_##__COUNTER__ \
    __attribute__((section("toysh_section"))) = {name, help, func}
extern const ToyshCommand __start_toysh_section;
extern const ToyshCommand __stop_toysh_section;
#define TOYSH_SECTION_BEGIN()   ((const ToyshCommand**)&__start_toysh_section)
#define TOYSH_SECTION_END()     ((const ToyshCommand**)&__stop_toysh_section)

#endif

unsigned int toysh_get_command_count();
const ToyshCommand* toysh_find_command(const char* name);

#ifdef __cplusplus
}
#endif  //  __cplusplus


#endif  //  TOYSH_COMMAND_H
