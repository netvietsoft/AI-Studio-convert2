// Function: sub_1B975C
// RVA: 0x1b975c, Size: 380 bytes
int64_t sub_1B975C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1b9820
    __memcpy_chk(...); // call imported API via PLT at 0x1b9840
    __memcpy_chk(...); // call imported API via PLT at 0x1b9854
    __memcpy_chk(...); // call imported API via PLT at 0x1b9868
    memcpy(...); // call imported API via PLT at 0x1b989c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1b98d4
}
