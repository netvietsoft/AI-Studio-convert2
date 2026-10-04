// Function: sub_E8B48
// RVA: 0xe8b48, Size: 236 bytes
int64_t sub_E8B48(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe8b80
    (*x8)(...); // indirect call at 0xe8bb0
    realloc(...); // call imported API via PLT at 0xe8be0
    abort(...); // call imported API via PLT at 0xe8c24
    _ZdlPv(...); // call imported API via PLT at 0xe8c2c
}
