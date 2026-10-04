// Function: __cxa_guard_release
// RVA: 0xceb74, Size: 168 bytes
int64_t __cxa_guard_release(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0xceb9c
    pthread_mutex_unlock(...); // call imported API via PLT at 0xcebb4
    void* g_104218 = (void*)0x104218; // global ref
    pthread_cond_broadcast(...); // call imported API via PLT at 0xcebc8
    return a0;
    const char* s_4971f = "%s failed to acquire mutex"; // string xref
    const char* s_491ae = "%s failed to release mutex"; // string xref
    const char* s_49b1f = "__cxa_guard_release"; // string xref
    const char* s_4b20e = "%s failed to broadcast"; // string xref
    const char* s_49b1f = "__cxa_guard_release"; // string xref
    sub_754CC(...); // call internal func at 0xcec18
}
