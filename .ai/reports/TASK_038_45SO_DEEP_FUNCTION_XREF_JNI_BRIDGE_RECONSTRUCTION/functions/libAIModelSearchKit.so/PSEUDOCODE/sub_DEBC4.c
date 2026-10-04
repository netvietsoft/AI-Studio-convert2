// Function: sub_DEBC4
// RVA: 0xdebc4, Size: 296 bytes
int64_t sub_DEBC4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xdec48
    abort(...); // call imported API via PLT at 0xdec58
    malloc(...); // call imported API via PLT at 0xdec60
    memmove(...); // call imported API via PLT at 0xdec7c
    return a0;
    abort(...); // call imported API via PLT at 0xdecc4
    free(...); // call imported API via PLT at 0xdecdc
}
