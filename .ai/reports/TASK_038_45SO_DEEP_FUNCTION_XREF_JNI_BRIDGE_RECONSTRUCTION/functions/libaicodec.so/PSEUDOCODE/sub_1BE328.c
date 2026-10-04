// Function: sub_1BE328
// RVA: 0x1be328, Size: 348 bytes
int64_t sub_1BE328(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be3d4
    __memcpy_chk(...); // call imported API via PLT at 0x1be3ec
    memcpy(...); // call imported API via PLT at 0x1be43c
    memcpy(...); // call imported API via PLT at 0x1be44c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be480
}
