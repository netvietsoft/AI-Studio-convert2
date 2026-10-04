// Function: sub_1BA868
// RVA: 0x1ba868, Size: 248 bytes
int64_t sub_1BA868(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1ba8f4
    __memcpy_chk(...); // call imported API via PLT at 0x1ba908
    memcpy(...); // call imported API via PLT at 0x1ba92c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1ba95c
}
