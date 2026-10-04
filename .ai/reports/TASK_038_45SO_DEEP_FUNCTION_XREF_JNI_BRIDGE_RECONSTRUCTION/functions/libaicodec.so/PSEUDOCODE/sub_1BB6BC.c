// Function: sub_1BB6BC
// RVA: 0x1bb6bc, Size: 204 bytes
int64_t sub_1BB6BC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb738
    memcpy(...); // call imported API via PLT at 0x1bb758
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb784
}
