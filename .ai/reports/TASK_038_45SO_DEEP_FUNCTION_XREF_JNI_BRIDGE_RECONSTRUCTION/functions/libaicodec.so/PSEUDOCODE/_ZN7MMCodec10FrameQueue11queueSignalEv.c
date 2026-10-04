// Function: MMCodec::FrameQueue::queueSignal()
// RVA: 0x1546f8, Size: 56 bytes
int64_t _ZN7MMCodec10FrameQueue11queueSignalEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15470c
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x154714
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x15471c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15472c
}
