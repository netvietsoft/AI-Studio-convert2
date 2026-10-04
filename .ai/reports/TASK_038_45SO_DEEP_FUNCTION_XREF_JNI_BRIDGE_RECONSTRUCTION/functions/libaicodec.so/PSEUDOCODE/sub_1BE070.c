// Function: sub_1BE070
// RVA: 0x1be070, Size: 348 bytes
int64_t sub_1BE070(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be11c
    __memcpy_chk(...); // call imported API via PLT at 0x1be134
    memcpy(...); // call imported API via PLT at 0x1be184
    memcpy(...); // call imported API via PLT at 0x1be194
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be1c8
}
