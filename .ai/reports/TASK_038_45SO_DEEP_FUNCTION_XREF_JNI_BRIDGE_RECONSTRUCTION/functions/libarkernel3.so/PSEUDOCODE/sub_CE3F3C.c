// Function: sub_CE3F3C
// RVA: 0xce3f3c, Size: 448 bytes
int64_t sub_CE3F3C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_CE3C68(...); // call internal func at 0xce3f78
    pthread_mutex_init(...); // call imported API via PLT at 0xce3fac
    pthread_cond_init(...); // call imported API via PLT at 0xce3fc8
    pthread_mutex_destroy(...); // call imported API via PLT at 0xce3fd8
    pthread_mutex_lock(...); // call imported API via PLT at 0xce3fe4
    pthread_create(...); // call imported API via PLT at 0xce4000
    pthread_mutex_unlock(...); // call imported API via PLT at 0xce4030
    pthread_mutex_destroy(...); // call imported API via PLT at 0xce4044
    pthread_cond_destroy(...); // call imported API via PLT at 0xce4050
    sub_CE3D10(...); // call internal func at 0xce405c
    sub_CE40FC(...); // call internal func at 0xce408c
    const char* s_24384b = "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/utils/thread_utils.c"; // string xref
    const char* s_21c66f = "int Reset(WebPWorker *const)"; // string xref
    const char* s_1e53ba = "!ok || (worker->status_ == OK)"; // string xref
    __assert2(...); // call imported API via PLT at 0xce40dc
    return a0;
}
