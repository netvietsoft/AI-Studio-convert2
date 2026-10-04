// Function: sub_1E99F0
// RVA: 0x1e99f0, Size: 388 bytes
int64_t sub_1E99F0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcmp(...); // call imported API via PLT at 0x1e9a28
    void* g_97b98 = (void*)0x97b98; // global ref
    void* g_97910 = (void*)0x97910; // global ref
    sub_1EBC84(...); // call internal func at 0x1e9aa0
    void* g_97b98 = (void*)0x97b98; // global ref
    void* g_97910 = (void*)0x97910; // global ref
    sub_1EBC84(...); // call internal func at 0x1e9ad8
    __stack_chk_fail(...); // call imported API via PLT at 0x1e9b2c
    return a0;
}
