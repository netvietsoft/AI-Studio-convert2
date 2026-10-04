// Function: sub_E41A8
// RVA: 0xe41a8, Size: 268 bytes
int64_t sub_E41A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    realloc(...); // call imported API via PLT at 0xe41f4
    (*x8)(...); // indirect call at 0xe4228
    realloc(...); // call imported API via PLT at 0xe4260
    memcpy(...); // call imported API via PLT at 0xe427c
    return a0;
    abort(...); // call imported API via PLT at 0xe42a0
    abort(...); // call imported API via PLT at 0xe42a4
    _ZdlPv(...); // call imported API via PLT at 0xe42ac
}
