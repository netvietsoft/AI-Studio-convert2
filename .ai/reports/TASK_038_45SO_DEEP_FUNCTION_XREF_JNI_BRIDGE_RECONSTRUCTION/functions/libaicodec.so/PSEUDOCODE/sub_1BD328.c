// Function: sub_1BD328
// RVA: 0x1bd328, Size: 232 bytes
int64_t sub_1BD328(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd3b8
    memcpy(...); // call imported API via PLT at 0x1bd3dc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd40c
}
