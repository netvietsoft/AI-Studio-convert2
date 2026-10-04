// Function: MMCodec::PacketQueue::~PacketQueue()
// RVA: 0x158584, Size: 192 bytes
int64_t _ZN7MMCodec11PacketQueueD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1585a8
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x1585b8
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x1585c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1585c8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1585d0
    sub_15954C(...); // call internal func at 0x1585f8
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x158600
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158608
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x158610
    _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEED2Ev(...); // call imported API via PLT at 0x158618
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x15863c
    sub_CEBC4(...); // call internal func at 0x158640
}
