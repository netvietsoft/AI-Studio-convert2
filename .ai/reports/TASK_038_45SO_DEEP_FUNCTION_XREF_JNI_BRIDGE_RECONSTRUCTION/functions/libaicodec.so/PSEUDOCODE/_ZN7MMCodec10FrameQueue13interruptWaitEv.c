// Function: MMCodec::FrameQueue::interruptWait()
// RVA: 0x154c74, Size: 60 bytes
int64_t _ZN7MMCodec10FrameQueue13interruptWaitEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x154c88
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x154c94
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154c9c
    return a0;
}
