// Function: sub_1BD84C
// RVA: 0x1bd84c, Size: 240 bytes
int64_t sub_1BD84C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bd8d4
    memcpy(...); // call imported API via PLT at 0x1bd8f8
    memcpy(...); // call imported API via PLT at 0x1bd908
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd938
}
