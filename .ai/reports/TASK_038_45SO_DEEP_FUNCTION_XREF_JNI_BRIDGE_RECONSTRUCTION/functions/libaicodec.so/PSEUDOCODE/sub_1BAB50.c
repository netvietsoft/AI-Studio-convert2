// Function: sub_1BAB50
// RVA: 0x1bab50, Size: 252 bytes
int64_t sub_1BAB50(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1babe0
    __memcpy_chk(...); // call imported API via PLT at 0x1babf4
    memcpy(...); // call imported API via PLT at 0x1bac18
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bac48
}
