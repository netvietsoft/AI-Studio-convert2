// Function: __emutls_get_address
// RVA: 0xeb1ec, Size: 492 bytes
int64_t __emutls_get_address(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0xeb218
    realloc(...); // call imported API via PLT at 0xeb248
    memset(...); // call imported API via PLT at 0xeb268
    void* g_104488 = (void*)0x104488; // global ref
    pthread_once(...); // call imported API via PLT at 0xeb284
    void* g_104010 = (void*)0x104010; // global ref
    pthread_mutex_lock(...); // call imported API via PLT at 0xeb28c
    void* g_104498 = (void*)0x104498; // global ref
    pthread_mutex_unlock(...); // call imported API via PLT at 0xeb2b8
    pthread_getspecific(...); // call imported API via PLT at 0xeb2c4
    malloc(...); // call imported API via PLT at 0xeb2e0
    void* g_104010 = (void*)0x104010; // global ref
    memset(...); // call imported API via PLT at 0xeb2f8
    pthread_setspecific(...); // call imported API via PLT at 0xeb310
    void* g_1040e2 = (void*)0x1040e2; // global ref
    return a0;
    void* g_1040ee = (void*)0x1040ee; // global ref
    malloc(...); // call imported API via PLT at 0xeb364
    void* g_1040f1 = (void*)0x1040f1; // global ref
    memcpy(...); // call imported API via PLT at 0xeb390
    memset(...); // call imported API via PLT at 0xeb3a4
    return a0;
    abort(...); // call imported API via PLT at 0xeb3c8
    abort(...); // call imported API via PLT at 0xeb3cc
    abort(...); // call imported API via PLT at 0xeb3d0
    abort(...); // call imported API via PLT at 0xeb3d4
}
