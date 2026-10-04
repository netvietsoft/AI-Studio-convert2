// Function: sub_E2A54
// RVA: 0xe2a54, Size: 388 bytes
int64_t sub_E2A54(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe2ac0
    abort(...); // call imported API via PLT at 0xe2ad0
    realloc(...); // call imported API via PLT at 0xe2b28
    abort(...); // call imported API via PLT at 0xe2b38
    malloc(...); // call imported API via PLT at 0xe2b40
    memcpy(...); // call imported API via PLT at 0xe2b5c
    malloc(...); // call imported API via PLT at 0xe2b68
    memmove(...); // call imported API via PLT at 0xe2b84
    return a0;
    abort(...); // call imported API via PLT at 0xe2bcc
    abort(...); // call imported API via PLT at 0xe2bd0
}
