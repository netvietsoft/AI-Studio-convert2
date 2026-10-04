// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVFrame>>::put(std::__ndk1::shared_ptr<AVFrame> const&)
// RVA: 0xd091c, Size: 408 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE3putERKS4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd0954
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0xd0980
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd09ac
    return a0;
    sub_D2C5C(...); // call internal func at 0xd0a24
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xd0a70
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd0a94
    __stack_chk_fail(...); // call imported API via PLT at 0xd0ab0
}
