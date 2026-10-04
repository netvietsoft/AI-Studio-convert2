// Function: sub_8F93A4
// RVA: 0x8f93a4, Size: 224 bytes
int64_t sub_8F93A4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x8f9404
    (*x8)(...); // indirect call at 0x8f944c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x8f9480
}
