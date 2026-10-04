// Function: sub_1BBD24
// RVA: 0x1bbd24, Size: 204 bytes
int64_t sub_1BBD24(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bbda0
    memcpy(...); // call imported API via PLT at 0x1bbdc0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bbdec
}
