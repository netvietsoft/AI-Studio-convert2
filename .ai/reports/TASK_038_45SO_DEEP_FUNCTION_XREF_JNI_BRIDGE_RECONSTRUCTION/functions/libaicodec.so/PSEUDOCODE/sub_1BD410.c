// Function: sub_1BD410
// RVA: 0x1bd410, Size: 232 bytes
int64_t sub_1BD410(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd4a0
    memcpy(...); // call imported API via PLT at 0x1bd4c4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd4f4
}
