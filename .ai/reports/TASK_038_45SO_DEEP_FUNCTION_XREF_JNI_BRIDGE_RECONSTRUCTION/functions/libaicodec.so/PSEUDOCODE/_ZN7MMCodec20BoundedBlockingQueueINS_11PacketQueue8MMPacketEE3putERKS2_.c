// Function: MMCodec::BoundedBlockingQueue<MMCodec::PacketQueue::MMPacket>::put(MMCodec::PacketQueue::MMPacket const&)
// RVA: 0x158c24, Size: 424 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE3putERKS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x158c5c
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x158c88
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158cb4
    return a0;
    sub_159774(...); // call internal func at 0x158d2c
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x158d88
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158dac
    __stack_chk_fail(...); // call imported API via PLT at 0x158dc8
}
