// Function: sub_1D50CC
// RVA: 0x1d50cc, Size: 640 bytes
int64_t sub_1D50CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1d5130
    (*x28)(...); // indirect call at 0x1d5258
    void* g_20203f = (void*)0x20203f; // global ref
    (*x13)(...); // indirect call at 0x1d52c0
    (*x28)(...); // indirect call at 0x1d52d8
    free(...); // call imported API via PLT at 0x1d5310
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1d5348
}
