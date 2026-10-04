// Function: sub_1BAD70
// RVA: 0x1bad70, Size: 292 bytes
int64_t sub_1BAD70(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bae1c
    __memcpy_chk(...); // call imported API via PLT at 0x1bae34
    memcpy(...); // call imported API via PLT at 0x1bae5c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bae90
}
