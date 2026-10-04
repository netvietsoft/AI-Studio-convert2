// Function: sub_30F0C
// RVA: 0x30f0c, Size: 588 bytes
int64_t sub_30F0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0x30f54
    (*x8)(...); // indirect call at 0x30f88
    (*x8)(...); // indirect call at 0x30fac
    realloc(...); // call imported API via PLT at 0x30fd8
    realloc(...); // call imported API via PLT at 0x31014
    (*x8)(...); // indirect call at 0x31048
    (*x8)(...); // indirect call at 0x3106c
    realloc(...); // call imported API via PLT at 0x310ac
    (*x8)(...); // indirect call at 0x310f0
    return a0;
    abort(...); // call imported API via PLT at 0x3113c
    abort(...); // call imported API via PLT at 0x31140
    abort(...); // call imported API via PLT at 0x31144
    abort(...); // call imported API via PLT at 0x31148
    _ZdlPv(...); // call imported API via PLT at 0x31150
}
