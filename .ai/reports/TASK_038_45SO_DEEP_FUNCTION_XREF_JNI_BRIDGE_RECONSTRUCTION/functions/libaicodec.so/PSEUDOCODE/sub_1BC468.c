// Function: sub_1BC468
// RVA: 0x1bc468, Size: 204 bytes
int64_t sub_1BC468(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bc4e4
    memcpy(...); // call imported API via PLT at 0x1bc504
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bc530
}
