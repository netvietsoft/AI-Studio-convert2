// Function: sub_1BC6CC
// RVA: 0x1bc6cc, Size: 212 bytes
int64_t sub_1BC6CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc750
    memcpy(...); // call imported API via PLT at 0x1bc770
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc79c
}
