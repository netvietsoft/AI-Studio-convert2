// Function: MMCodec::FrameQueue::put()
// RVA: 0x1540b8, Size: 268 bytes
int64_t _ZN7MMCodec10FrameQueue3putEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1540ec
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x154100
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154110
    pthread_self(...); // call imported API via PLT at 0x154134
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_7e534 = "put"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x154160
    pthread_self(...); // call imported API via PLT at 0x154184
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_7e534 = "put"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1541b4
    return a0;
}
