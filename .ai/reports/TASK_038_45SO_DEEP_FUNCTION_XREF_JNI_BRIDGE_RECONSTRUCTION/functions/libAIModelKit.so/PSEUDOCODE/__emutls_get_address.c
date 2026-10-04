// Function: __emutls_get_address
// RVA: 0x3af2c, Size: 492 bytes
int64_t __emutls_get_address(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x3af58
    realloc(...); // call imported API via PLT at 0x3af88
    memset(...); // call imported API via PLT at 0x3afa8
    void* g_4c688 = (void*)0x4c688; // global ref
    pthread_once(...); // call imported API via PLT at 0x3afc4
    void* g_4c010 = (void*)0x4c010; // global ref
    pthread_mutex_lock(...); // call imported API via PLT at 0x3afcc
    void* g_4c698 = (void*)0x4c698; // global ref
    pthread_mutex_unlock(...); // call imported API via PLT at 0x3aff8
    pthread_getspecific(...); // call imported API via PLT at 0x3b004
    malloc(...); // call imported API via PLT at 0x3b020
    void* g_4c010 = (void*)0x4c010; // global ref
    memset(...); // call imported API via PLT at 0x3b038
    pthread_setspecific(...); // call imported API via PLT at 0x3b050
    void* g_4c0e2 = (void*)0x4c0e2; // global ref
    return a0;
    void* g_4c0ee = (void*)0x4c0ee; // global ref
    malloc(...); // call imported API via PLT at 0x3b0a4
    void* g_4c0f1 = (void*)0x4c0f1; // global ref
    memcpy(...); // call imported API via PLT at 0x3b0d0
    memset(...); // call imported API via PLT at 0x3b0e4
    return a0;
    abort(...); // call imported API via PLT at 0x3b108
    abort(...); // call imported API via PLT at 0x3b10c
    abort(...); // call imported API via PLT at 0x3b110
    abort(...); // call imported API via PLT at 0x3b114
}
