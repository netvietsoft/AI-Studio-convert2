// Function: sub_1BAE94
// RVA: 0x1bae94, Size: 292 bytes
int64_t sub_1BAE94(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1baf40
    __memcpy_chk(...); // call imported API via PLT at 0x1baf58
    memcpy(...); // call imported API via PLT at 0x1baf80
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bafb4
}
