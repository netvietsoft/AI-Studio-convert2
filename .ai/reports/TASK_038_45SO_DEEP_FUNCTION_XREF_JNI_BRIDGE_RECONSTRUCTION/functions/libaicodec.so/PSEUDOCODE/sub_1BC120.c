// Function: sub_1BC120
// RVA: 0x1bc120, Size: 204 bytes
int64_t sub_1BC120(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc19c
    memcpy(...); // call imported API via PLT at 0x1bc1bc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc1e8
}
