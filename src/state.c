#include "toysh/state.h"

#define X(name) #name,
static const char* ToyshStateStrings[TOYSH_ENUM_LENGTH] = {TOYSH_STATE_ENUM()};
#undef X

const char* get_state_name(const ToyshState state) {
    if (state >= TOYSH_ENUM_LENGTH)
        return "UNKNOWN";
    return ToyshStateStrings[state];
}
