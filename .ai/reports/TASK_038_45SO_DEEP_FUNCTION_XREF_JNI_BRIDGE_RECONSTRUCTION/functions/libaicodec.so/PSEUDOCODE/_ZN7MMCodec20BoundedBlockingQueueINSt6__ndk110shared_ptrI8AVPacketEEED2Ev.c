// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVPacket>>::~BoundedBlockingQueue()
// RVA: 0xd1208, Size: 240 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEED2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_201010 = (void*)0x201010; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd1244
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xd1254
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xd125c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd1264
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd126c
    sub_D131C(...); // call internal func at 0xd1298
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xd12a0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd12a8
    sub_D131C(...); // call internal func at 0xd12b0
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0xd12b8
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0xd12c0
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0xd12c8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xd12f0
    sub_CEBC4(...); // call internal func at 0xd12f4
}
