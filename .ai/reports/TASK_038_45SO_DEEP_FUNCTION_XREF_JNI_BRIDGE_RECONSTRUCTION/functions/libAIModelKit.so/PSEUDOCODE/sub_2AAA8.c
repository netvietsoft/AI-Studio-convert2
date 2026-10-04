// Function: sub_2AAA8
// RVA: 0x2aaa8, Size: 880 bytes
int64_t sub_2AAA8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_44e88 = (void*)0x44e88; // global ref
    malloc(...); // call imported API via PLT at 0x2ac3c
    realloc(...); // call imported API via PLT at 0x2ac9c
    malloc(...); // call imported API via PLT at 0x2acb0
    memcpy(...); // call imported API via PLT at 0x2accc
    malloc(...); // call imported API via PLT at 0x2ad78
    void* g_464c8 = (void*)0x464c8; // global ref
    return a0;
    _ZSt9terminatev(...); // call imported API via PLT at 0x2ae08
    abort(...); // call imported API via PLT at 0x2ae0c
    abort(...); // call imported API via PLT at 0x2ae10
}
