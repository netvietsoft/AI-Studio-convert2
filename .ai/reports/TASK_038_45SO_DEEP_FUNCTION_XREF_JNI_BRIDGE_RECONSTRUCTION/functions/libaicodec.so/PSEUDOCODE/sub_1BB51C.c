// Function: sub_1BB51C
// RVA: 0x1bb51c, Size: 208 bytes
int64_t sub_1BB51C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb598
    memcpy(...); // call imported API via PLT at 0x1bb5bc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb5e8
}
