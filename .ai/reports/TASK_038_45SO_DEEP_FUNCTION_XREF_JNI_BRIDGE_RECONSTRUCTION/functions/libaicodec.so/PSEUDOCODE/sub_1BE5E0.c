// Function: sub_1BE5E0
// RVA: 0x1be5e0, Size: 348 bytes
int64_t sub_1BE5E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be68c
    __memcpy_chk(...); // call imported API via PLT at 0x1be6a4
    memcpy(...); // call imported API via PLT at 0x1be6f4
    memcpy(...); // call imported API via PLT at 0x1be704
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be738
}
