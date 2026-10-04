// Function: sub_1B9F98
// RVA: 0x1b9f98, Size: 380 bytes
int64_t sub_1B9F98(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba05c
    __memcpy_chk(...); // call imported API via PLT at 0x1ba07c
    __memcpy_chk(...); // call imported API via PLT at 0x1ba090
    memcpy(...); // call imported API via PLT at 0x1ba0d8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba110
}
