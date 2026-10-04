// Function: sub_E5140
// RVA: 0xe5140, Size: 248 bytes
int64_t sub_E5140(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe5180
    (*x8)(...); // indirect call at 0xe51cc
    return a0;
    abort(...); // call imported API via PLT at 0xe5210
    _ZdlPv(...); // call imported API via PLT at 0xe5218
    return a0;
    return a0;
}
