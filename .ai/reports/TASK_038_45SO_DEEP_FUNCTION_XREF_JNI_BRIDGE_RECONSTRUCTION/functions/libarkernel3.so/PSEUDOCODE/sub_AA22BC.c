// Function: sub_AA22BC
// RVA: 0xaa22bc, Size: 144 bytes
int64_t sub_AA22BC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call imported API via PLT at 0xaa2320
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xaa2348
}
