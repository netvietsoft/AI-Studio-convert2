// Function: sub_B76024
// RVA: 0xb76024, Size: 592 bytes
int64_t sub_B76024(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    memmove(...); // call imported API via PLT at 0xb760e8
    sub_B75A38(...); // call internal func at 0xb7610c
    memmove(...); // call imported API via PLT at 0xb7614c
    memmove(...); // call imported API via PLT at 0xb76174
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb761b0
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    return a0;
}
