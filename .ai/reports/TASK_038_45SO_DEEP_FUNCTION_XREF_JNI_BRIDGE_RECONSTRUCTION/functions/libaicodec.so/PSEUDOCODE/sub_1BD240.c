// Function: sub_1BD240
// RVA: 0x1bd240, Size: 232 bytes
int64_t sub_1BD240(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd2d0
    memcpy(...); // call imported API via PLT at 0x1bd2f4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd324
}
