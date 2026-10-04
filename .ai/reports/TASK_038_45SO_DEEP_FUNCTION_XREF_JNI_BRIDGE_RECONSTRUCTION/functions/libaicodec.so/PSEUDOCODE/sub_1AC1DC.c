// Function: sub_1AC1DC
// RVA: 0x1ac1dc, Size: 492 bytes
int64_t sub_1AC1DC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_66f70 = (void*)0x66f70; // global ref
    malloc(...); // call imported API via PLT at 0x1ac2fc
    (*x25)(...); // indirect call at 0x1ac344
    (*x8)(...); // indirect call at 0x1ac360
    free(...); // call imported API via PLT at 0x1ac3a0
    return a0;
}
