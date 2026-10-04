// Function: sub_E81B0
// RVA: 0xe81b0, Size: 172 bytes
int64_t sub_E81B0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xe81d4
    realloc(...); // call imported API via PLT at 0xe820c
    memcpy(...); // call imported API via PLT at 0xe8228
    return a0;
    abort(...); // call imported API via PLT at 0xe824c
    _ZdlPv(...); // call imported API via PLT at 0xe8254
}
