// Function: sub_D4390
// RVA: 0xd4390, Size: 216 bytes
int64_t sub_D4390(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xd43d4
    abort(...); // call imported API via PLT at 0xd43e8
    malloc(...); // call imported API via PLT at 0xd43f0
    memmove(...); // call imported API via PLT at 0xd4414
    return a0;
    abort(...); // call imported API via PLT at 0xd4460
}
