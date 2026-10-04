// Function: MMCodec::FrameQueue::next()
// RVA: 0x154730, Size: 304 bytes
int64_t _ZN7MMCodec10FrameQueue4nextEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x154764
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x15479c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1547ac
    pthread_self(...); // call imported API via PLT at 0x1547d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_86614 = "next"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1547fc
    pthread_self(...); // call imported API via PLT at 0x154820
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_86614 = "next"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x154850
    return a0;
}
