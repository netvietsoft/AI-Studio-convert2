// Function: sub_1BC2B8
// RVA: 0x1bc2b8, Size: 216 bytes
int64_t sub_1BC2B8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc340
    memcpy(...); // call imported API via PLT at 0x1bc360
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc38c
}
