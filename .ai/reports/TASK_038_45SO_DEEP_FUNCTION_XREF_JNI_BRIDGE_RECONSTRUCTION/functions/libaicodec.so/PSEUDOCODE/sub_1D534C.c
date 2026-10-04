// Function: sub_1D534C
// RVA: 0x1d534c, Size: 992 bytes
int64_t sub_1D534C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1d54d8
    (*x24)(...); // indirect call at 0x1d5504
    (*x24)(...); // indirect call at 0x1d552c
    void* g_2020e3 = (void*)0x2020e3; // global ref
    (*x26)(...); // indirect call at 0x1d5598
    (*x8)(...); // indirect call at 0x1d561c
    (*x26)(...); // indirect call at 0x1d564c
    (*x8)(...); // indirect call at 0x1d56d0
    free(...); // call imported API via PLT at 0x1d56f0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1d5728
}
