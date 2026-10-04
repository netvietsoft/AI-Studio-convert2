// Function: sub_1BDC18
// RVA: 0x1bdc18, Size: 252 bytes
int64_t sub_1BDC18(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bdca8
    memcpy(...); // call imported API via PLT at 0x1bdcd0
    memcpy(...); // call imported API via PLT at 0x1bdce0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bdd10
}
