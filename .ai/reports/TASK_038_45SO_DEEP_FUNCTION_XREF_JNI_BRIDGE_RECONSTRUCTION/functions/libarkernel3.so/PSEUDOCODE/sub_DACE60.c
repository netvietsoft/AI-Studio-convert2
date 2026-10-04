// Function: sub_DACE60
// RVA: 0xdace60, Size: 128 bytes
int64_t sub_DACE60(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdaceac
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xdacedc
}
