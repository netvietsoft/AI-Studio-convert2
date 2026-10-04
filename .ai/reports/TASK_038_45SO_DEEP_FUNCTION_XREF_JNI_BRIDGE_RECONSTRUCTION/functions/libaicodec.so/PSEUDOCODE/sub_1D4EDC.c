// Function: sub_1D4EDC
// RVA: 0x1d4edc, Size: 496 bytes
int64_t sub_1D4EDC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1d4f3c
    (*x27)(...); // indirect call at 0x1d4fe8
    (*x27)(...); // indirect call at 0x1d5060
    free(...); // call imported API via PLT at 0x1d5090
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1d50c8
}
