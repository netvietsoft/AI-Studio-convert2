// Function: sub_DD08C
// RVA: 0xdd08c, Size: 544 bytes
int64_t sub_DD08C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xdd0dc
    memcpy(...); // call imported API via PLT at 0xdd0f8
    realloc(...); // call imported API via PLT at 0xdd138
    (*x8)(...); // indirect call at 0xdd16c
    realloc(...); // call imported API via PLT at 0xdd198
    realloc(...); // call imported API via PLT at 0xdd1e8
    realloc(...); // call imported API via PLT at 0xdd250
    return a0;
    abort(...); // call imported API via PLT at 0xdd284
    abort(...); // call imported API via PLT at 0xdd288
    abort(...); // call imported API via PLT at 0xdd28c
    abort(...); // call imported API via PLT at 0xdd290
    abort(...); // call imported API via PLT at 0xdd294
    _ZdlPv(...); // call imported API via PLT at 0xdd2a4
}
