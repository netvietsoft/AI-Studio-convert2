// Function: sub_1BCBBC
// RVA: 0x1bcbbc, Size: 204 bytes
int64_t sub_1BCBBC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bcc38
    memcpy(...); // call imported API via PLT at 0x1bcc58
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bcc84
}
