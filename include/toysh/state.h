#ifndef TOYSH_STATE_H
#define TOYSH_STATE_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#define TOYSH_STATE_ENUM() \
    X(TOYSH_OK) \
    X(TOYSH_ERR) \
    X(TOYSH_ERR_ARG_1_NULL) \
    X(TOYSH_ERR_ARG_2_NULL) \
    X(TOYSH_ERR_ARG_3_NULL) \

#define X(name) name,
typedef enum{
    TOYSH_STATE_ENUM()
    TOYSH_ENUM_LENGTH,
}ToyshState;
#undef X

const char* get_state_name(ToyshState state);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif //  TOYSH_STATE_H
