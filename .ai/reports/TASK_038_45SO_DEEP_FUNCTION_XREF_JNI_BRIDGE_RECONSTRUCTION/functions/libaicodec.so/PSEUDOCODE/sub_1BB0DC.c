// Function: sub_1BB0DC
// RVA: 0x1bb0dc, Size: 296 bytes
int64_t sub_1BB0DC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __memcpy_chk(...); // call imported API via PLT at 0x1bb188
    __memcpy_chk(...); // call imported API via PLT at 0x1bb1a0
    memcpy(...); // call imported API via PLT at 0x1bb1cc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bb200
}
