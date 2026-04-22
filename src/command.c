#include "toysh/command.h"
#include <string.h>

unsigned int toysh_get_command_count() {
    const ToyshCommand** section_begin = TOYSH_SECTION_BEGIN();
    const ToyshCommand** section_end = TOYSH_SECTION_END();
    return (unsigned int)(section_end - section_begin);
}

const ToyshCommand* toysh_find_command(const char* name) {
    if (name == NULL)
        return NULL;
    const ToyshCommand** section_begin = TOYSH_SECTION_BEGIN();
    const unsigned int count = toysh_get_command_count();

    for (unsigned int i = 0; i < count; ++i) {
        const ToyshCommand* cmd = section_begin[i];
        if (cmd && cmd->name && strcmp(cmd->name, name) == 0)
            return section_begin[i];
    }
    return NULL;
}
