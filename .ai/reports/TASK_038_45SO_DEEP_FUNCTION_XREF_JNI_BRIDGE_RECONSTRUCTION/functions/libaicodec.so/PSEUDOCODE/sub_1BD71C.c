// Function: sub_1BD71C
// RVA: 0x1bd71c, Size: 152 bytes
int64_t sub_1BD71C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call imported API via PLT at 0x1bd784
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1bd7b0
}
