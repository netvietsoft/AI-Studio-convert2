// Function: sub_1BD93C
// RVA: 0x1bd93c, Size: 240 bytes
int64_t sub_1BD93C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd9c4
    memcpy(...); // call imported API via PLT at 0x1bd9e8
    memcpy(...); // call imported API via PLT at 0x1bd9f8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bda28
}
