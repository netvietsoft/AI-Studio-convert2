// Function: sub_DBEAC
// RVA: 0xdbeac, Size: 364 bytes
int64_t sub_DBEAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdbee8
    realloc(...); // call imported API via PLT at 0xdbf50
    (*x8)(...); // indirect call at 0xdbf80
    (*x8)(...); // indirect call at 0xdbfa4
    realloc(...); // call imported API via PLT at 0xdbfdc
    return a0;
    abort(...); // call imported API via PLT at 0xdc00c
    abort(...); // call imported API via PLT at 0xdc010
}
