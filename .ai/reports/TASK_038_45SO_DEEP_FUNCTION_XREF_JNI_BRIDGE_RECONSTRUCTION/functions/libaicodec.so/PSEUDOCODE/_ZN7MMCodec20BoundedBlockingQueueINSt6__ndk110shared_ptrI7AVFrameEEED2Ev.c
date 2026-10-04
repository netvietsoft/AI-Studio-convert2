// Function: MMCodec::BoundedBlockingQueue<std::__ndk1::shared_ptr<AVFrame>>::~BoundedBlockingQueue()
// RVA: 0xd102c, Size: 240 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEED2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_201010 = (void*)0x201010; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd1068
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xd1078
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xd1080
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd1088
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xd1090
    sub_D14D8(...); // call internal func at 0xd10bc
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0xd10c4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xd10cc
    sub_D14D8(...); // call internal func at 0xd10d4
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0xd10dc
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0xd10e4
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0xd10ec
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xd1114
    sub_CEBC4(...); // call internal func at 0xd1118
}
