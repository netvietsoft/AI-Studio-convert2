// Function: sub_DD15D8
// RVA: 0xdd15d8, Size: 1060 bytes
int64_t sub_DD15D8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xdd165c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xdd1680
    _ZdlPv(...); // call imported API via PLT at 0xdd1684
    (*x8)(...); // indirect call at 0xdd19c8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xdd19f8
}
