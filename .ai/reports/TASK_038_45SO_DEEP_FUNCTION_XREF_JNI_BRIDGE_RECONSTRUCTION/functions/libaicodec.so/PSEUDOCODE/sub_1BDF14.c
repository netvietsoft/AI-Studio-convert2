// Function: sub_1BDF14
// RVA: 0x1bdf14, Size: 348 bytes
int64_t sub_1BDF14(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bdfc0
    __memcpy_chk(...); // call imported API via PLT at 0x1bdfd8
    memcpy(...); // call imported API via PLT at 0x1be028
    memcpy(...); // call imported API via PLT at 0x1be038
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be06c
}
