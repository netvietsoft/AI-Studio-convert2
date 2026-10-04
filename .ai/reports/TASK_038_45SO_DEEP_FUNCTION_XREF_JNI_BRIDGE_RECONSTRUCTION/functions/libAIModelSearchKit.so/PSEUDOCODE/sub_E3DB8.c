// Function: sub_E3DB8
// RVA: 0xe3db8, Size: 368 bytes
int64_t sub_E3DB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe3ddc
    realloc(...); // call imported API via PLT at 0xe3e08
    realloc(...); // call imported API via PLT at 0xe3e70
    memcpy(...); // call imported API via PLT at 0xe3e8c
    realloc(...); // call imported API via PLT at 0xe3ec4
    return a0;
    abort(...); // call imported API via PLT at 0xe3efc
    abort(...); // call imported API via PLT at 0xe3f00
    abort(...); // call imported API via PLT at 0xe3f04
    _ZdlPv(...); // call imported API via PLT at 0xe3f20
}
