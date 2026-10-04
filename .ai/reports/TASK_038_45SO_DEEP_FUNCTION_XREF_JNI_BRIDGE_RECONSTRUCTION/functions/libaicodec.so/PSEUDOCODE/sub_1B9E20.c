// Function: sub_1B9E20
// RVA: 0x1b9e20, Size: 376 bytes
int64_t sub_1B9E20(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9ee4
    __memcpy_chk(...); // call imported API via PLT at 0x1b9f04
    __memcpy_chk(...); // call imported API via PLT at 0x1b9f18
    memcpy(...); // call imported API via PLT at 0x1b9f5c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b9f94
}
