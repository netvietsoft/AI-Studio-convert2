// Function: sub_1BBAB8
// RVA: 0x1bbab8, Size: 212 bytes
int64_t sub_1BBAB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bbb3c
    memcpy(...); // call imported API via PLT at 0x1bbb5c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bbb88
}
