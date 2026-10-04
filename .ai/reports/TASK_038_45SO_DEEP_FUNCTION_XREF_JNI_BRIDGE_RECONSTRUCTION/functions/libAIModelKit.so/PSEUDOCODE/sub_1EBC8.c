// Function: sub_1EBC8
// RVA: 0x1ebc8, Size: 156 bytes
int64_t sub_1EBC8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0x1ebe0
    pthread_mutex_unlock(...); // call imported API via PLT at 0x1ebfc
    void* g_4c418 = (void*)0x4c418; // global ref
    pthread_cond_broadcast(...); // call imported API via PLT at 0x1ec10
    return a0;
    const char* s_1017b = "%s failed to acquire mutex"; // string xref
    const char* s_fd59 = "%s failed to release mutex"; // string xref
    const char* s_10dcd = "__cxa_guard_abort"; // string xref
    const char* s_11501 = "%s failed to broadcast"; // string xref
    const char* s_10dcd = "__cxa_guard_abort"; // string xref
}
