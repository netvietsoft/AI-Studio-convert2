// Function: MMCodec::BoundedBlockingQueue<MMCodec::PacketQueue::MMPacket>::force_put(MMCodec::PacketQueue::MMPacket const&)
// RVA: 0x158b2c, Size: 248 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE9force_putERKS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x158b48
    sub_159774(...); // call internal func at 0x158b90
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x158bec
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158bf8
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158c18
}
