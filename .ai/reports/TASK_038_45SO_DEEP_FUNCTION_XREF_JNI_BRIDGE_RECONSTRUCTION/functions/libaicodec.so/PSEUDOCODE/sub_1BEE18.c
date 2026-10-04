// Function: sub_1BEE18
// RVA: 0x1bee18, Size: 364 bytes
int64_t sub_1BEE18(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1beec4
    __memcpy_chk(...); // call imported API via PLT at 0x1beedc
    memcpy(...); // call imported API via PLT at 0x1bef3c
    memcpy(...); // call imported API via PLT at 0x1bef4c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bef80
}
