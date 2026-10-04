// Function: sub_1BA404
// RVA: 0x1ba404, Size: 376 bytes
int64_t sub_1BA404(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba4c8
    __memcpy_chk(...); // call imported API via PLT at 0x1ba4e8
    __memcpy_chk(...); // call imported API via PLT at 0x1ba4fc
    memcpy(...); // call imported API via PLT at 0x1ba540
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba578
}
