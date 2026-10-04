// Function: sub_1BE484
// RVA: 0x1be484, Size: 348 bytes
int64_t sub_1BE484(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be530
    __memcpy_chk(...); // call imported API via PLT at 0x1be548
    memcpy(...); // call imported API via PLT at 0x1be598
    memcpy(...); // call imported API via PLT at 0x1be5a8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be5dc
}
