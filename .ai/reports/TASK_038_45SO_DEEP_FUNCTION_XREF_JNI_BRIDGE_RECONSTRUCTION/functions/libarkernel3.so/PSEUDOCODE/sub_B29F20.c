// Function: sub_B29F20
// RVA: 0xb29f20, Size: 84 bytes
int64_t sub_B29F20(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B29F74(...); // call internal func at 0xb29f48
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb29f6c
    _ZdlPv(...); // call imported API via PLT at 0xb29f70
}
