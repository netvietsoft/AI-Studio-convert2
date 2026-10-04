// Function: sub_C9EDE0
// RVA: 0xc9ede0, Size: 108 bytes
int64_t sub_C9EDE0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_10ad300 = (void*)0x10ad300; // global ref
    (*x8)(...); // indirect call at 0xc9ee24
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xc9ee48
}
