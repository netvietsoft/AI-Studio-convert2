// Function: sub_AB3F18
// RVA: 0xab3f18, Size: 460 bytes
int64_t sub_AB3F18(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call imported API via PLT at 0xab3fc4
    sub_AB3D48(...); // call internal func at 0xab4000
    (*x8)(...); // indirect call at 0xab4028
    _ZdlPv(...); // call imported API via PLT at 0xab4038
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xab408c
    __stack_chk_fail(...); // call imported API via PLT at 0xab40a8
    return a0;
}
