// Function: sub_1BDA2C
// RVA: 0x1bda2c, Size: 240 bytes
int64_t sub_1BDA2C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bdab4
    memcpy(...); // call imported API via PLT at 0x1bdad8
    memcpy(...); // call imported API via PLT at 0x1bdae8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bdb18
}
