// Function: sub_1BC7A0
// RVA: 0x1bc7a0, Size: 212 bytes
int64_t sub_1BC7A0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc824
    memcpy(...); // call imported API via PLT at 0x1bc844
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc870
}
