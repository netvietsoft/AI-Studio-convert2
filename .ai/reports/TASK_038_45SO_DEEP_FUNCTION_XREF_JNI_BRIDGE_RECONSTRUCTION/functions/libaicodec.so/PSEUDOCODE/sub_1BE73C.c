// Function: sub_1BE73C
// RVA: 0x1be73c, Size: 348 bytes
int64_t sub_1BE73C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be7e8
    __memcpy_chk(...); // call imported API via PLT at 0x1be800
    memcpy(...); // call imported API via PLT at 0x1be850
    memcpy(...); // call imported API via PLT at 0x1be860
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be894
}
