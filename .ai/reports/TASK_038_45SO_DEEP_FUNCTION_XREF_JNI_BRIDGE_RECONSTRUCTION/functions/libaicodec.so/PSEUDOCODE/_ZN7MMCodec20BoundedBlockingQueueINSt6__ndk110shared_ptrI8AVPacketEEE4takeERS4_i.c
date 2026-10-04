// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVPacket>>::take(std::__ndk1::shared_ptr<AVPacket>&, int)
// RVA: 0xe0390, Size: 576 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE4takeERS4_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xe03cc
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0xe03d4
    sub_E1320(...); // call internal func at 0xe03f8
    (*x8)(...); // indirect call at 0xe0490
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xe0498
    (*x8)(...); // indirect call at 0xe04d8
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0xe04e0
    _ZdlPv(...); // call imported API via PLT at 0xe050c
    void* g_67008 = (void*)0x67008; // global ref
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xe052c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xe0540
    return a0;
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0xe0574
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xe05b0
    __stack_chk_fail(...); // call imported API via PLT at 0xe05cc
}
