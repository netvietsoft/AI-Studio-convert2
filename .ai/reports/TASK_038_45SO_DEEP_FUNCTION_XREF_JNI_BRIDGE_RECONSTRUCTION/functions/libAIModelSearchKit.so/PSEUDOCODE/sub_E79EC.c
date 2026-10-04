// Function: sub_E79EC
// RVA: 0xe79ec, Size: 516 bytes
int64_t sub_E79EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe7a14
    (*x8)(...); // indirect call at 0xe7a38
    realloc(...); // call imported API via PLT at 0xe7a64
    realloc(...); // call imported API via PLT at 0xe7abc
    memcpy(...); // call imported API via PLT at 0xe7ad8
    (*x8)(...); // indirect call at 0xe7b00
    return a0;
    abort(...); // call imported API via PLT at 0xe7b4c
    abort(...); // call imported API via PLT at 0xe7b50
    _ZdlPv(...); // call imported API via PLT at 0xe7b58
    return a0;
    return a0;
    return a0;
}
