// Function: sub_DA8690
// RVA: 0xda8690, Size: 444 bytes
int64_t sub_DA8690(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xda86bc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xda8700
    (*x8)(...); // indirect call at 0xda8750
    (*x8)(...); // indirect call at 0xda87cc
    return a0;
}
