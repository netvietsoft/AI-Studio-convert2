// Function: MMCodec::BoundedBlockingQueue<MMCodec::PacketQueue::MMPacket>::take(MMCodec::PacketQueue::MMPacket&, int)
// RVA: 0x15909c, Size: 604 bytes
int64_t _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE4takeERS2_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1590e0
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0x1590e8
    sub_15A078(...); // call internal func at 0x15910c
    (*x8)(...); // indirect call at 0x15919c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x1591a4
    (*x8)(...); // indirect call at 0x1591f8
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x159200
    _ZdlPv(...); // call imported API via PLT at 0x15922c
    void* g_67008 = (void*)0x67008; // global ref
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x15924c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x159260
    return a0;
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x15929c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1592d8
    __stack_chk_fail(...); // call imported API via PLT at 0x1592f4
}
