// Function: sub_DEAB0
// RVA: 0xdeab0, Size: 276 bytes
int64_t sub_DEAB0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xdeaf0
    (*x8)(...); // indirect call at 0xdeb2c
    (*x8)(...); // indirect call at 0xdeb50
    realloc(...); // call imported API via PLT at 0xdeb7c
    return a0;
    abort(...); // call imported API via PLT at 0xdebb0
    abort(...); // call imported API via PLT at 0xdebb4
    _ZdlPv(...); // call imported API via PLT at 0xdebbc
}
