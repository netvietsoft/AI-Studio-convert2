// Function: sub_E11CC
// RVA: 0xe11cc, Size: 588 bytes
int64_t sub_E11CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe1214
    (*x8)(...); // indirect call at 0xe1248
    (*x8)(...); // indirect call at 0xe126c
    realloc(...); // call imported API via PLT at 0xe1298
    realloc(...); // call imported API via PLT at 0xe12d4
    (*x8)(...); // indirect call at 0xe1308
    (*x8)(...); // indirect call at 0xe132c
    realloc(...); // call imported API via PLT at 0xe136c
    (*x8)(...); // indirect call at 0xe13b0
    return a0;
    abort(...); // call imported API via PLT at 0xe13fc
    abort(...); // call imported API via PLT at 0xe1400
    abort(...); // call imported API via PLT at 0xe1404
    abort(...); // call imported API via PLT at 0xe1408
    _ZdlPv(...); // call imported API via PLT at 0xe1410
}
