// Function: sub_8117C
// RVA: 0x8117c, Size: 88 bytes
int64_t sub_8117C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0x8119c
    pthread_mutex_unlock(...); // call imported API via PLT at 0x811b0
    void* g_102690 = (void*)0x102690; // global ref
    pthread_cond_broadcast(...); // call imported API via PLT at 0x811bc
    return a0;
    sub_754CC(...); // call internal func at 0x811d0
}
