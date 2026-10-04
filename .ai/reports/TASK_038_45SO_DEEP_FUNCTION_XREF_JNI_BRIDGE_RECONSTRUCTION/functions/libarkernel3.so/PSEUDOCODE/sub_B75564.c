// Function: sub_B75564
// RVA: 0xb75564, Size: 360 bytes
int64_t sub_B75564(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    memmove(...); // call imported API via PLT at 0xb75644
    sub_B75A38(...); // call internal func at 0xb75660
    memmove(...); // call imported API via PLT at 0xb75688
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb756c8
}
