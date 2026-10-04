// Function: sub_1BB204
// RVA: 0x1bb204, Size: 296 bytes
int64_t sub_1BB204(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb2b0
    __memcpy_chk(...); // call imported API via PLT at 0x1bb2c8
    memcpy(...); // call imported API via PLT at 0x1bb2f4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb328
}
