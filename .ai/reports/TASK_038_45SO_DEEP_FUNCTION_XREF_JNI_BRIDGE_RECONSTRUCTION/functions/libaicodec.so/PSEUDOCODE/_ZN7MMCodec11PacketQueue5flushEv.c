// Function: MMCodec::PacketQueue::flush()
// RVA: 0x158684, Size: 132 bytes
int64_t _ZN7MMCodec11PacketQueue5flushEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1586a8
    sub_15954C(...); // call internal func at 0x1586d0
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x1586d8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1586e0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x158704
}
