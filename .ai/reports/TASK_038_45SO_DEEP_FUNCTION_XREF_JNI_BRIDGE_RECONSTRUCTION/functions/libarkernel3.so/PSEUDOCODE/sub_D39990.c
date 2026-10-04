// Function: sub_D39990
// RVA: 0xd39990, Size: 188 bytes
int64_t sub_D39990(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    frexp(...); // call imported API via PLT at 0xd399bc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xd399f8
    sub_B7ADB8(...); // call internal func at 0xd39a24
    ldexp(...); // call imported API via PLT at 0xd39a2c
    return a0;
}
