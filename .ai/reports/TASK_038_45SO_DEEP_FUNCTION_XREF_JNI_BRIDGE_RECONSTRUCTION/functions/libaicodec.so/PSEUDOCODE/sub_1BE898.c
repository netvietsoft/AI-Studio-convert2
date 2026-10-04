// Function: sub_1BE898
// RVA: 0x1be898, Size: 348 bytes
int64_t sub_1BE898(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1be944
    __memcpy_chk(...); // call imported API via PLT at 0x1be95c
    memcpy(...); // call imported API via PLT at 0x1be9ac
    memcpy(...); // call imported API via PLT at 0x1be9bc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1be9f0
}
