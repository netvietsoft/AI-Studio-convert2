// Function: sub_32794
// RVA: 0x32794, Size: 388 bytes
int64_t sub_32794(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x32800
    abort(...); // call imported API via PLT at 0x32810
    realloc(...); // call imported API via PLT at 0x32868
    abort(...); // call imported API via PLT at 0x32878
    malloc(...); // call imported API via PLT at 0x32880
    memcpy(...); // call imported API via PLT at 0x3289c
    malloc(...); // call imported API via PLT at 0x328a8
    memmove(...); // call imported API via PLT at 0x328c4
    return a0;
    abort(...); // call imported API via PLT at 0x3290c
    abort(...); // call imported API via PLT at 0x32910
}
