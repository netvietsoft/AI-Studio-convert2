// Function: sub_1BEB50
// RVA: 0x1beb50, Size: 348 bytes
int64_t sub_1BEB50(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bebfc
    __memcpy_chk(...); // call imported API via PLT at 0x1bec14
    memcpy(...); // call imported API via PLT at 0x1bec64
    memcpy(...); // call imported API via PLT at 0x1bec74
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1beca8
}
