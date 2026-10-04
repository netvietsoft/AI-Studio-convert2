// Function: sub_C9F1F8
// RVA: 0xc9f1f8, Size: 108 bytes
int64_t sub_C9F1F8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_10ad3a8 = (void*)0x10ad3a8; // global ref
    (*x8)(...); // indirect call at 0xc9f23c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xc9f260
}
