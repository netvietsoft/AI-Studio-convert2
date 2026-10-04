// Function: sub_86202C
// RVA: 0x86202c, Size: 188 bytes
int64_t sub_86202C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x8620b4
    sub_863360(...); // call internal func at 0x8620d0
    return a0;
}
