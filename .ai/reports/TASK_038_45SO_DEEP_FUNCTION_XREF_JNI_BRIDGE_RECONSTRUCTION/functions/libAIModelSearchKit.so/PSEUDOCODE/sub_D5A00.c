// Function: sub_D5A00
// RVA: 0xd5a00, Size: 300 bytes
int64_t sub_D5A00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xd5a30
    (*x8)(...); // indirect call at 0xd5a54
    realloc(...); // call imported API via PLT at 0xd5aa0
    (*x8)(...); // indirect call at 0xd5ad0
    return a0;
    abort(...); // call imported API via PLT at 0xd5b1c
    _ZdlPv(...); // call imported API via PLT at 0xd5b24
}
