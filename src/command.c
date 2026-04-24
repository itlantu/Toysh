#include "toysh/command.h"

TOYSH_COMMAND_INIT();

const struct ToyshCommand* toysh_command_section_begin(void) {
    return TOYSH_COMMAND_SECTION_BEGIN();
}

const struct ToyshCommand* toysh_command_section_end(void) {
    return TOYSH_COMMAND_SECTION_END();
}
