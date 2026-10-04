// Function: sub_1BBB8C
// RVA: 0x1bbb8c, Size: 204 bytes
int64_t sub_1BBB8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bbc08
    memcpy(...); // call imported API via PLT at 0x1bbc28
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bbc54
}
