// Function: sub_8C050C
// RVA: 0x8c050c, Size: 760 bytes
int64_t sub_8C050C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_8C08FC(...); // call internal func at 0x8c05c4
    sub_8C0804(...); // call internal func at 0x8c0624
    sub_8C0898(...); // call internal func at 0x8c062c
    return a0;
    sub_8C08E8(...); // call internal func at 0x8c0668
    sub_8C0898(...); // call internal func at 0x8c0674
    __stack_chk_fail(...); // call imported API via PLT at 0x8c0690
    memset(...); // call imported API via PLT at 0x8c06d8
    return a0;
    memset(...); // call imported API via PLT at 0x8c0790
    return a0;
}
