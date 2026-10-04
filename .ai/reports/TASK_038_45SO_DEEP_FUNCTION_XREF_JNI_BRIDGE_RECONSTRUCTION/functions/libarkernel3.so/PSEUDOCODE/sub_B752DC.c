// Function: sub_B752DC
// RVA: 0xb752dc, Size: 356 bytes
int64_t sub_B752DC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    sub_B75A38(...); // call internal func at 0xb75398
    memmove(...); // call imported API via PLT at 0xb753c8
    memmove(...); // call imported API via PLT at 0xb753fc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb7543c
}
