// Function: sub_1BC94C
// RVA: 0x1bc94c, Size: 216 bytes
int64_t sub_1BC94C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc9d4
    memcpy(...); // call imported API via PLT at 0x1bc9f4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bca20
}
