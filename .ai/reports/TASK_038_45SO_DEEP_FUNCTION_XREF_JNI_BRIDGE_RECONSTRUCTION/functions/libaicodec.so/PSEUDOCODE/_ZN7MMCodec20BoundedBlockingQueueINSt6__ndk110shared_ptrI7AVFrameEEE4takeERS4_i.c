// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVFrame>>::take(std::__ndk1::shared_ptr<AVFrame>&, int)
// RVA: 0xdc2c4, Size: 576 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE4takeERS4_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdc300
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0xdc308
    sub_E05D0(...); // call internal func at 0xdc32c
    (*x8)(...); // indirect call at 0xdc3c4
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdc3cc
    (*x8)(...); // indirect call at 0xdc40c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xdc414
    _ZdlPv(...); // call imported API via PLT at 0xdc440
    void* g_67008 = (void*)0x67008; // global ref
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xdc460
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdc474
    return a0;
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0xdc4a8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdc4e4
    __stack_chk_fail(...); // call imported API via PLT at 0xdc500
}
