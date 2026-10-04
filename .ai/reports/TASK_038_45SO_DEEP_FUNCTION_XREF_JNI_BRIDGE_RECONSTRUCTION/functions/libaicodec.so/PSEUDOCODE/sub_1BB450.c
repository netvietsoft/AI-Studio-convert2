// Function: sub_1BB450
// RVA: 0x1bb450, Size: 204 bytes
int64_t sub_1BB450(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb4cc
    memcpy(...); // call imported API via PLT at 0x1bb4ec
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb518
}
