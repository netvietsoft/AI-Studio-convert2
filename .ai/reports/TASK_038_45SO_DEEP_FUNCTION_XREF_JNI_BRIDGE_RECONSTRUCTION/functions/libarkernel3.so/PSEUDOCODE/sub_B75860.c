// Function: sub_B75860
// RVA: 0xb75860, Size: 472 bytes
int64_t sub_B75860(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    memmove(...); // call imported API via PLT at 0xb75994
    sub_B75A38(...); // call internal func at 0xb759b4
    memmove(...); // call imported API via PLT at 0xb759dc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb75a34
}
