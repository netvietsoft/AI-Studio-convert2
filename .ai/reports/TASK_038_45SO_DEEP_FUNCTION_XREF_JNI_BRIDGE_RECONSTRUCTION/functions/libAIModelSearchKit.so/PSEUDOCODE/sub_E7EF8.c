// Function: sub_E7EF8
// RVA: 0xe7ef8, Size: 224 bytes
int64_t sub_E7EF8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe7f38
    (*x8)(...); // indirect call at 0xe7f84
    return a0;
    abort(...); // call imported API via PLT at 0xe7fc8
    _ZdlPv(...); // call imported API via PLT at 0xe7fd0
}
