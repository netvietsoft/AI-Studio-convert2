// Function: sub_1BB9EC
// RVA: 0x1bb9ec, Size: 204 bytes
int64_t sub_1BB9EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bba68
    memcpy(...); // call imported API via PLT at 0x1bba88
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bbab4
}
