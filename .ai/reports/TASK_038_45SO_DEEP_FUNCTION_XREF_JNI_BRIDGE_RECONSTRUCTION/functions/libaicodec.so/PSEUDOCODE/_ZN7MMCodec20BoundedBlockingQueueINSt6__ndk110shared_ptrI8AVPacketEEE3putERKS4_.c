// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVPacket>>::put(std::__ndk1::shared_ptr<AVPacket> const&)
// RVA: 0xdc5a0, Size: 408 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xdc5d8
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0xdc604
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdc630
    return a0;
    sub_E07B0(...); // call internal func at 0xdc6a8
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xdc6f4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xdc718
    __stack_chk_fail(...); // call imported API via PLT at 0xdc734
}
