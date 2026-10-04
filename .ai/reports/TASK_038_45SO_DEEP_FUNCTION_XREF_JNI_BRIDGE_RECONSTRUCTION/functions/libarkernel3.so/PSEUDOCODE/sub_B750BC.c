// Function: sub_B750BC
// RVA: 0xb750bc, Size: 256 bytes
int64_t sub_B750BC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    sub_B75A38(...); // call internal func at 0xb7515c
    memmove(...); // call imported API via PLT at 0xb7517c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb751b8
}
