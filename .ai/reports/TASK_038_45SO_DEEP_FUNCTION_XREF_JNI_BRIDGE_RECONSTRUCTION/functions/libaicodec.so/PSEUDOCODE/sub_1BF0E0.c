// Function: sub_1BF0E0
// RVA: 0x1bf0e0, Size: 348 bytes
int64_t sub_1BF0E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bf18c
    __memcpy_chk(...); // call imported API via PLT at 0x1bf1a4
    memcpy(...); // call imported API via PLT at 0x1bf1f4
    memcpy(...); // call imported API via PLT at 0x1bf204
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bf238
}
