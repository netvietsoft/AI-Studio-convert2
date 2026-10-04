// Function: sub_1BAFB8
// RVA: 0x1bafb8, Size: 292 bytes
int64_t sub_1BAFB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb064
    __memcpy_chk(...); // call imported API via PLT at 0x1bb07c
    memcpy(...); // call imported API via PLT at 0x1bb0a4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb0d8
}
