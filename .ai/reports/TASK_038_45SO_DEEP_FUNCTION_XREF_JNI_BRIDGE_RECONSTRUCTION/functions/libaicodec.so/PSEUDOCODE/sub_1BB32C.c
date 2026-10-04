// Function: sub_1BB32C
// RVA: 0x1bb32c, Size: 292 bytes
int64_t sub_1BB32C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb3d8
    __memcpy_chk(...); // call imported API via PLT at 0x1bb3f0
    memcpy(...); // call imported API via PLT at 0x1bb418
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb44c
}
