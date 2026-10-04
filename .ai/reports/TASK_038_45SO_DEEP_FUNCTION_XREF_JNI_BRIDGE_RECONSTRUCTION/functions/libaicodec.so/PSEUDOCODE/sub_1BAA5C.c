// Function: sub_1BAA5C
// RVA: 0x1baa5c, Size: 244 bytes
int64_t sub_1BAA5C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1baae4
    __memcpy_chk(...); // call imported API via PLT at 0x1baaf8
    memcpy(...); // call imported API via PLT at 0x1bab1c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bab4c
}
