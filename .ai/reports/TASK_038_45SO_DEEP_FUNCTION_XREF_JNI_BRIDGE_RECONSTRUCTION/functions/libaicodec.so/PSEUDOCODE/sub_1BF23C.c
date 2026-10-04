// Function: sub_1BF23C
// RVA: 0x1bf23c, Size: 348 bytes
int64_t sub_1BF23C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bf2e8
    __memcpy_chk(...); // call imported API via PLT at 0x1bf300
    memcpy(...); // call imported API via PLT at 0x1bf350
    memcpy(...); // call imported API via PLT at 0x1bf360
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bf394
}
