// Function: sub_AA3300
// RVA: 0xaa3300, Size: 104 bytes
int64_t sub_AA3300(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_10a1b38 = (void*)0x10a1b38; // global ref
    sub_AA4020(...); // call internal func at 0xaa3338
    sub_AA3368(...); // call internal func at 0xaa3340
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xaa3364
}
