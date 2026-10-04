// Function: sub_2E904
// RVA: 0x2e904, Size: 296 bytes
int64_t sub_2E904(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x2e988
    abort(...); // call imported API via PLT at 0x2e998
    malloc(...); // call imported API via PLT at 0x2e9a0
    memmove(...); // call imported API via PLT at 0x2e9bc
    return a0;
    abort(...); // call imported API via PLT at 0x2ea04
    free(...); // call imported API via PLT at 0x2ea1c
}
