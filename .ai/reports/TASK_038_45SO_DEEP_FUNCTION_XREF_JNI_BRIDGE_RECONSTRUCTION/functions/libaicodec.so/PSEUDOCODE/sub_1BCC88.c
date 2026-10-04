// Function: sub_1BCC88
// RVA: 0x1bcc88, Size: 208 bytes
int64_t sub_1BCC88(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bcd08
    memcpy(...); // call imported API via PLT at 0x1bcd28
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bcd54
}
