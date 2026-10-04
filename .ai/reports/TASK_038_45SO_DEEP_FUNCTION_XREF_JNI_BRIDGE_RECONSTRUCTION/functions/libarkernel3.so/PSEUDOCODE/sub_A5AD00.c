// Function: sub_A5AD00
// RVA: 0xa5ad00, Size: 228 bytes
int64_t sub_A5AD00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_2932ac = (void*)0x2932ac; // global ref
    sub_A5B250(...); // call internal func at 0xa5ad4c
    void* g_2932ac = (void*)0x2932ac; // global ref
    sub_A5B250(...); // call internal func at 0xa5ad78
    wgpuTextureRelease(...); // call imported API via PLT at 0xa5ad80
    wgpuTextureReference(...); // call imported API via PLT at 0xa5ad8c
    void* g_2932ac = (void*)0x2932ac; // global ref
    sub_A5B250(...); // call internal func at 0xa5adb4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xa5ade0
}
