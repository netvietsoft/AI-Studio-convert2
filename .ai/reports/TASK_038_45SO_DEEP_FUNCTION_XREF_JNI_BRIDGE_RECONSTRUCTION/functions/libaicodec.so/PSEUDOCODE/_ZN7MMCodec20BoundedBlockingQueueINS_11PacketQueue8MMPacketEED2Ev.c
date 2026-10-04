// Function: MMCodec::BoundedBlockingQueue<MMCodec::PacketQueue::MMPacket>::~BoundedBlockingQueue()
// RVA: 0x158708, Size: 240 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEED2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202010 = (void*)0x202010; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x158744
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x158754
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x15875c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158764
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15876c
    sub_15954C(...); // call internal func at 0x158798
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x1587a0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1587a8
    sub_15954C(...); // call internal func at 0x1587b0
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0x1587b8
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0x1587c0
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x1587c8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1587f0
    sub_CEBC4(...); // call internal func at 0x1587f4
}
