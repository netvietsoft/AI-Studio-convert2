// Function: sub_1BCAF0
// RVA: 0x1bcaf0, Size: 204 bytes
int64_t sub_1BCAF0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bcb6c
    memcpy(...); // call imported API via PLT at 0x1bcb8c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bcbb8
}
