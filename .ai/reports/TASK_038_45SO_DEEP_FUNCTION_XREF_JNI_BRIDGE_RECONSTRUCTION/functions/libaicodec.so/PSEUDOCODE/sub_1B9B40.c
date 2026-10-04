// Function: sub_1B9B40
// RVA: 0x1b9b40, Size: 360 bytes
int64_t sub_1B9B40(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9c04
    __memcpy_chk(...); // call imported API via PLT at 0x1b9c18
    __memcpy_chk(...); // call imported API via PLT at 0x1b9c2c
    memcpy(...); // call imported API via PLT at 0x1b9c70
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b9ca4
}
