// Function: sub_81080
// RVA: 0x81080, Size: 252 bytes
int64_t sub_81080(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0x810ac
    pthread_cond_wait(...); // call imported API via PLT at 0x810c4
    pthread_mutex_unlock(...); // call imported API via PLT at 0x810f8
    pthread_mutex_unlock(...); // call imported API via PLT at 0x81114
    (*x20)(...); // indirect call at 0x8111c
    pthread_mutex_lock(...); // call imported API via PLT at 0x81128
    pthread_mutex_unlock(...); // call imported API via PLT at 0x8113c
    void* g_102690 = (void*)0x102690; // global ref
    pthread_cond_broadcast(...); // call imported API via PLT at 0x81148
    return a0;
}
