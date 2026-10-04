// Function: sub_1BC1EC
// RVA: 0x1bc1ec, Size: 204 bytes
int64_t sub_1BC1EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc268
    memcpy(...); // call imported API via PLT at 0x1bc288
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc2b4
}
