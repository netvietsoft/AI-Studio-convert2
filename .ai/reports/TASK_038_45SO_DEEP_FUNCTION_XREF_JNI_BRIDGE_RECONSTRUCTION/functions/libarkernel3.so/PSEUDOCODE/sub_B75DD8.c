// Function: sub_B75DD8
// RVA: 0xb75dd8, Size: 288 bytes
int64_t sub_B75DD8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    sub_B75A38(...); // call internal func at 0xb75e74
    memmove(...); // call imported API via PLT at 0xb75e94
    memmove(...); // call imported API via PLT at 0xb75ec0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb75ef4
}
