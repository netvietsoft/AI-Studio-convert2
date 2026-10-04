// Function: sub_1BA114
// RVA: 0x1ba114, Size: 376 bytes
int64_t sub_1BA114(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba1d8
    __memcpy_chk(...); // call imported API via PLT at 0x1ba1f8
    __memcpy_chk(...); // call imported API via PLT at 0x1ba20c
    memcpy(...); // call imported API via PLT at 0x1ba250
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba288
}
