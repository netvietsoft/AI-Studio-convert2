// Function: sub_1B98D8
// RVA: 0x1b98d8, Size: 308 bytes
int64_t sub_1B98D8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9978
    __memcpy_chk(...); // call imported API via PLT at 0x1b9998
    __memcpy_chk(...); // call imported API via PLT at 0x1b99ac
    memcpy(...); // call imported API via PLT at 0x1b99d4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b9a08
}
