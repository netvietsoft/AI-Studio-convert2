// Function: sub_1D4C60
// RVA: 0x1d4c60, Size: 636 bytes
int64_t sub_1D4C60(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1d4cc0
    (*x24)(...); // indirect call at 0x1d4dec
    void* g_20203f = (void*)0x20203f; // global ref
    (*x13)(...); // indirect call at 0x1d4e50
    (*x24)(...); // indirect call at 0x1d4e68
    free(...); // call imported API via PLT at 0x1d4ea0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1d4ed8
}
