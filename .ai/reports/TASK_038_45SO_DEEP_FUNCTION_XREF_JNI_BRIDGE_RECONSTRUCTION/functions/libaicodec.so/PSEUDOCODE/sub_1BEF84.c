// Function: sub_1BEF84
// RVA: 0x1bef84, Size: 348 bytes
int64_t sub_1BEF84(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bf030
    __memcpy_chk(...); // call imported API via PLT at 0x1bf048
    memcpy(...); // call imported API via PLT at 0x1bf098
    memcpy(...); // call imported API via PLT at 0x1bf0a8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bf0dc
}
