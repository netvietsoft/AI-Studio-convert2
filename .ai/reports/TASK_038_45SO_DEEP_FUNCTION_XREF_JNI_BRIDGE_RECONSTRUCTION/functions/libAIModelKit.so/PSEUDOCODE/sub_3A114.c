// Function: sub_3A114
// RVA: 0x3a114, Size: 312 bytes
int64_t sub_3A114(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_4c480 = (void*)0x4c480; // global ref
    void* g_4c680 = (void*)0x4c680; // global ref
    pthread_mutex_lock(...); // call imported API via PLT at 0x3a158
    free(...); // call imported API via PLT at 0x3a1dc
    void* g_4c458 = (void*)0x4c458; // global ref
    pthread_mutex_unlock(...); // call imported API via PLT at 0x3a230
    return a0;
}
