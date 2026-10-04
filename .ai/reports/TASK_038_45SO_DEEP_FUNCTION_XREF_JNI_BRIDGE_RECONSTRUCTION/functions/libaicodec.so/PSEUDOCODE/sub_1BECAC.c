// Function: sub_1BECAC
// RVA: 0x1becac, Size: 364 bytes
int64_t sub_1BECAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bed58
    __memcpy_chk(...); // call imported API via PLT at 0x1bed70
    memcpy(...); // call imported API via PLT at 0x1bedd0
    memcpy(...); // call imported API via PLT at 0x1bede0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bee14
}
