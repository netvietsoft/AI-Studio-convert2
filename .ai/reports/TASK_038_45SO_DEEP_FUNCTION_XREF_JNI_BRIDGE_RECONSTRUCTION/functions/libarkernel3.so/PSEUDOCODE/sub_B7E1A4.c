// Function: sub_B7E1A4
// RVA: 0xb7e1a4, Size: 156 bytes
int64_t sub_B7E1A4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x20)(...); // indirect call at 0xb7e1fc
    sub_B7E240(...); // call internal func at 0xb7e20c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb7e23c
}
