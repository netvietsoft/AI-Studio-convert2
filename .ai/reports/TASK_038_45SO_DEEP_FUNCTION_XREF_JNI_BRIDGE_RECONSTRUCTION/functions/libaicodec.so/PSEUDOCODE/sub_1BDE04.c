// Function: sub_1BDE04
// RVA: 0x1bde04, Size: 272 bytes
int64_t sub_1BDE04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bde98
    memcpy(...); // call imported API via PLT at 0x1bdec0
    memcpy(...); // call imported API via PLT at 0x1bded0
    memcpy(...); // call imported API via PLT at 0x1bdee0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bdf10
}
