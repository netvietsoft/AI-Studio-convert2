// Function: sub_B76548
// RVA: 0xb76548, Size: 460 bytes
int64_t sub_B76548(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2c2acd = (void*)0x2c2acd; // global ref
    memmove(...); // call imported API via PLT at 0xb76610
    sub_B75A38(...); // call internal func at 0xb76634
    memmove(...); // call imported API via PLT at 0xb76674
    memmove(...); // call imported API via PLT at 0xb766b8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xb76710
}
