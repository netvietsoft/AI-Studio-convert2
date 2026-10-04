// Function: sub_1BAC4C
// RVA: 0x1bac4c, Size: 292 bytes
int64_t sub_1BAC4C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bacf8
    __memcpy_chk(...); // call imported API via PLT at 0x1bad10
    memcpy(...); // call imported API via PLT at 0x1bad38
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bad6c
}
