// Function: sub_EA3D4
// RVA: 0xea3d4, Size: 312 bytes
int64_t sub_EA3D4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_104280 = (void*)0x104280; // global ref
    void* g_104480 = (void*)0x104480; // global ref
    pthread_mutex_lock(...); // call imported API via PLT at 0xea418
    free(...); // call imported API via PLT at 0xea49c
    void* g_104258 = (void*)0x104258; // global ref
    pthread_mutex_unlock(...); // call imported API via PLT at 0xea4f0
    return a0;
    sub_754CC(...); // call internal func at 0xea508
}
