// Function: sub_1BE1CC
// RVA: 0x1be1cc, Size: 348 bytes
int64_t sub_1BE1CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be278
    __memcpy_chk(...); // call imported API via PLT at 0x1be290
    memcpy(...); // call imported API via PLT at 0x1be2e0
    memcpy(...); // call imported API via PLT at 0x1be2f0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be324
}
