// Function: MMCodec::FrameQueue::notifyWritable()
// RVA: 0x1543d0, Size: 216 bytes
int64_t _ZN7MMCodec10FrameQueue14notifyWritableEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x154408
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_6fe91 = "notifyWritable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x154434
    pthread_self(...); // call imported API via PLT at 0x154458
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_6fe91 = "notifyWritable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x154480
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x154488
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x154494
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1544a4
}
