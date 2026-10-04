// Function: sub_1BA960
// RVA: 0x1ba960, Size: 252 bytes
int64_t sub_1BA960(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba9f0
    __memcpy_chk(...); // call imported API via PLT at 0x1baa04
    memcpy(...); // call imported API via PLT at 0x1baa28
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1baa58
}
