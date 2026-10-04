// Function: sub_C82F7C
// RVA: 0xc82f7c, Size: 112 bytes
int64_t sub_C82F7C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xc82fbc
    return a0;
    sub_C1187C(...); // call internal func at 0xc82fe0
    __stack_chk_fail(...); // call imported API via PLT at 0xc82fe4
}
