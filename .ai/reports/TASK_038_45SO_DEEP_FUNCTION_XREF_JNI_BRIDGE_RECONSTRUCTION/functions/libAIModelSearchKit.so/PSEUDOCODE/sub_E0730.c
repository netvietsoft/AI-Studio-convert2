// Function: sub_E0730
// RVA: 0xe0730, Size: 568 bytes
int64_t sub_E0730(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe077c
    (*x8)(...); // indirect call at 0xe07b0
    (*x8)(...); // indirect call at 0xe07d4
    realloc(...); // call imported API via PLT at 0xe080c
    realloc(...); // call imported API via PLT at 0xe0864
    realloc(...); // call imported API via PLT at 0xe08bc
    realloc(...); // call imported API via PLT at 0xe0908
    memcpy(...); // call imported API via PLT at 0xe0924
    return a0;
    abort(...); // call imported API via PLT at 0xe0948
    abort(...); // call imported API via PLT at 0xe094c
    abort(...); // call imported API via PLT at 0xe0950
    abort(...); // call imported API via PLT at 0xe0954
    abort(...); // call imported API via PLT at 0xe0958
    _ZdlPv(...); // call imported API via PLT at 0xe0960
}
