// Function: __cxa_guard_abort
// RVA: 0xcec1c, Size: 156 bytes
int64_t __cxa_guard_abort(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0xcec38
    pthread_mutex_unlock(...); // call imported API via PLT at 0xcec54
    void* g_104218 = (void*)0x104218; // global ref
    pthread_cond_broadcast(...); // call imported API via PLT at 0xcec68
    return a0;
    const char* s_4971f = "%s failed to acquire mutex"; // string xref
    const char* s_491ae = "%s failed to release mutex"; // string xref
    const char* s_4a803 = "__cxa_guard_abort"; // string xref
    const char* s_4b20e = "%s failed to broadcast"; // string xref
    const char* s_4a803 = "__cxa_guard_abort"; // string xref
    sub_754CC(...); // call internal func at 0xcecb4
}
