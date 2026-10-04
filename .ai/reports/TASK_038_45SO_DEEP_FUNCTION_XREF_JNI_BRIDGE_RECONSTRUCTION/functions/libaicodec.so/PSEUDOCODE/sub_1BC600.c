// Function: sub_1BC600
// RVA: 0x1bc600, Size: 204 bytes
int64_t sub_1BC600(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc67c
    memcpy(...); // call imported API via PLT at 0x1bc69c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc6c8
}
