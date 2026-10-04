// Function: sub_2E7F0
// RVA: 0x2e7f0, Size: 276 bytes
int64_t sub_2E7F0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x2e830
    (*x8)(...); // indirect call at 0x2e86c
    (*x8)(...); // indirect call at 0x2e890
    realloc(...); // call imported API via PLT at 0x2e8bc
    return a0;
    abort(...); // call imported API via PLT at 0x2e8f0
    abort(...); // call imported API via PLT at 0x2e8f4
    _ZdlPv(...); // call imported API via PLT at 0x2e8fc
}
