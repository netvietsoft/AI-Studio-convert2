// Function: sub_3820C
// RVA: 0x3820c, Size: 348 bytes
int64_t sub_3820C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x38234
    (*x8)(...); // indirect call at 0x38258
    realloc(...); // call imported API via PLT at 0x38284
    (*x8)(...); // indirect call at 0x382cc
    (*x8)(...); // indirect call at 0x382f0
    realloc(...); // call imported API via PLT at 0x3831c
    return a0;
    abort(...); // call imported API via PLT at 0x38354
    abort(...); // call imported API via PLT at 0x38358
    _ZdlPv(...); // call imported API via PLT at 0x38360
}
