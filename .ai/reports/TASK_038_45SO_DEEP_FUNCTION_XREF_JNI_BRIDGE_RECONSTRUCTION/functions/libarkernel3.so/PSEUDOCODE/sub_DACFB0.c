// Function: sub_DACFB0
// RVA: 0xdacfb0, Size: 140 bytes
int64_t sub_DACFB0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x9)(...); // indirect call at 0xdad010
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xdad034
    _ZdlPv(...); // call imported API via PLT at 0xdad038
}
