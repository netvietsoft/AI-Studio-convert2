// Function: sub_E1004
// RVA: 0xe1004, Size: 456 bytes
int64_t sub_E1004(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe1044
    (*x8)(...); // indirect call at 0xe1068
    realloc(...); // call imported API via PLT at 0xe10c4
    (*x8)(...); // indirect call at 0xe10fc
    (*x8)(...); // indirect call at 0xe1120
    realloc(...); // call imported API via PLT at 0xe1150
    return a0;
    abort(...); // call imported API via PLT at 0xe11a0
    abort(...); // call imported API via PLT at 0xe11a4
    _ZdlPv(...); // call imported API via PLT at 0xe11c4
}
