// Function: sub_1B9A0C
// RVA: 0x1b9a0c, Size: 308 bytes
int64_t sub_1B9A0C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9aac
    __memcpy_chk(...); // call imported API via PLT at 0x1b9acc
    __memcpy_chk(...); // call imported API via PLT at 0x1b9ae0
    memcpy(...); // call imported API via PLT at 0x1b9b08
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b9b3c
}
