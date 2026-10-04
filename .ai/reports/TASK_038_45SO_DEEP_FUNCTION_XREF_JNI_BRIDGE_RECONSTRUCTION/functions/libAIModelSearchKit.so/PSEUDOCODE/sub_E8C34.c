// Function: sub_E8C34
// RVA: 0xe8c34, Size: 360 bytes
int64_t sub_E8C34(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe8c84
    memcpy(...); // call imported API via PLT at 0xe8ca0
    realloc(...); // call imported API via PLT at 0xe8cd8
    (*x8)(...); // indirect call at 0xe8d0c
    return a0;
    abort(...); // call imported API via PLT at 0xe8d58
    abort(...); // call imported API via PLT at 0xe8d5c
    _ZdlPv(...); // call imported API via PLT at 0xe8d64
    return a0;
}
