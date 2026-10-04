// Function: sub_C9EF8C
// RVA: 0xc9ef8c, Size: 108 bytes
int64_t sub_C9EF8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_10ad340 = (void*)0x10ad340; // global ref
    (*x8)(...); // indirect call at 0xc9efd0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xc9eff4
}
