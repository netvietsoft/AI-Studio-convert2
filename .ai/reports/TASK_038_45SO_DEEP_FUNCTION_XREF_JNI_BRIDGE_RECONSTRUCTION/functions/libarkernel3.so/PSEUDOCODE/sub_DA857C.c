// Function: sub_DA857C
// RVA: 0xda857c, Size: 276 bytes
int64_t sub_DA857C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xda85e0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xda8660
    (*x8)(...); // indirect call at 0xda867c
    return a0;
}
