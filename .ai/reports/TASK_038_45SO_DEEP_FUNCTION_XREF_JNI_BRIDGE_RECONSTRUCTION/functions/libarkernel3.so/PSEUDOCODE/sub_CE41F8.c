// Function: sub_CE41F8
// RVA: 0xce41f8, Size: 176 bytes
int64_t sub_CE41F8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_CE4390(...); // call internal func at 0xce422c
    pthread_join(...); // call imported API via PLT at 0xce423c
    pthread_mutex_destroy(...); // call imported API via PLT at 0xce4244
    pthread_cond_destroy(...); // call imported API via PLT at 0xce4250
    sub_CE3D10(...); // call internal func at 0xce4258
    const char* s_24384b = "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/utils/thread_utils.c"; // string xref
    const char* s_25a331 = "void End(WebPWorker *const)"; // string xref
    const char* s_2706ed = "worker->status_ == NOT_OK"; // string xref
    __assert2(...); // call imported API via PLT at 0xce4298
    return a0;
}
