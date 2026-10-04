// Function: sub_1BCE24
// RVA: 0x1bce24, Size: 208 bytes
int64_t sub_1BCE24(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bcea0
    memcpy(...); // call imported API via PLT at 0x1bcec4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bcef0
}
