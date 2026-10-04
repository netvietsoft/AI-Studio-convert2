// Function: sub_C82EFC
// RVA: 0xc82efc, Size: 128 bytes
int64_t sub_C82EFC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xc82f50
    return a0;
    sub_C1187C(...); // call internal func at 0xc82f74
    __stack_chk_fail(...); // call imported API via PLT at 0xc82f78
}
