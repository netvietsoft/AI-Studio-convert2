// Function: sub_E3624
// RVA: 0xe3624, Size: 228 bytes
int64_t sub_E3624(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe3664
    (*x8)(...); // indirect call at 0xe36a0
    return a0;
    abort(...); // call imported API via PLT at 0xe36e4
    _ZdlPv(...); // call imported API via PLT at 0xe3700
}
