// Function: sub_E7D84
// RVA: 0xe7d84, Size: 372 bytes
int64_t sub_E7D84(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe7dd4
    memcpy(...); // call imported API via PLT at 0xe7df0
    realloc(...); // call imported API via PLT at 0xe7e28
    (*x8)(...); // indirect call at 0xe7e5c
    (*x8)(...); // indirect call at 0xe7e80
    realloc(...); // call imported API via PLT at 0xe7eac
    return a0;
    abort(...); // call imported API via PLT at 0xe7ee0
    abort(...); // call imported API via PLT at 0xe7ee4
    abort(...); // call imported API via PLT at 0xe7ee8
    _ZdlPv(...); // call imported API via PLT at 0xe7ef0
}
