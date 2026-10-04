// Function: sub_1BCD58
// RVA: 0x1bcd58, Size: 204 bytes
int64_t sub_1BCD58(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bcdd4
    memcpy(...); // call imported API via PLT at 0x1bcdf4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bce20
}
