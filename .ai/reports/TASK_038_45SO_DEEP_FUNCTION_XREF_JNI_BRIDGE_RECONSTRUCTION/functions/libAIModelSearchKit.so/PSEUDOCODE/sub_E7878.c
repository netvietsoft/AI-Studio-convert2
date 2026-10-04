// Function: sub_E7878
// RVA: 0xe7878, Size: 372 bytes
int64_t sub_E7878(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe78a0
    (*x8)(...); // indirect call at 0xe78c4
    realloc(...); // call imported API via PLT at 0xe78f0
    realloc(...); // call imported API via PLT at 0xe7948
    memcpy(...); // call imported API via PLT at 0xe7964
    realloc(...); // call imported API via PLT at 0xe799c
    return a0;
    abort(...); // call imported API via PLT at 0xe79d4
    abort(...); // call imported API via PLT at 0xe79d8
    abort(...); // call imported API via PLT at 0xe79dc
    _ZdlPv(...); // call imported API via PLT at 0xe79e4
}
