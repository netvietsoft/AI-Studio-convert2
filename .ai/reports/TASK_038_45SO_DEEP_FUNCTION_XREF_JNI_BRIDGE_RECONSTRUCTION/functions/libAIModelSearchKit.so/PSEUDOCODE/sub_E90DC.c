// Function: sub_E90DC
// RVA: 0xe90dc, Size: 396 bytes
int64_t sub_E90DC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe9174
    (*x8)(...); // indirect call at 0xe91a4
    realloc(...); // call imported API via PLT at 0xe91d4
    return a0;
    abort(...); // call imported API via PLT at 0xe9228
    _ZdlPv(...); // call imported API via PLT at 0xe9230
    return a0;
}
