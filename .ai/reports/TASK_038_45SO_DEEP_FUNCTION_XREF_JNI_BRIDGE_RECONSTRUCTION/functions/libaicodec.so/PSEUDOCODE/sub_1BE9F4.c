// Function: sub_1BE9F4
// RVA: 0x1be9f4, Size: 348 bytes
int64_t sub_1BE9F4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1beaa0
    __memcpy_chk(...); // call imported API via PLT at 0x1beab8
    memcpy(...); // call imported API via PLT at 0x1beb08
    memcpy(...); // call imported API via PLT at 0x1beb18
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1beb4c
}
