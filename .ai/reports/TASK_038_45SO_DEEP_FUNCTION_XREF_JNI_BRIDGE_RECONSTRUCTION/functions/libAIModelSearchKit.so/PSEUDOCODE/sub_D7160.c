// Function: sub_D7160
// RVA: 0xd7160, Size: 216 bytes
int64_t sub_D7160(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xd71a4
    abort(...); // call imported API via PLT at 0xd71b8
    malloc(...); // call imported API via PLT at 0xd71c0
    memmove(...); // call imported API via PLT at 0xd71e4
    return a0;
    abort(...); // call imported API via PLT at 0xd7230
}
