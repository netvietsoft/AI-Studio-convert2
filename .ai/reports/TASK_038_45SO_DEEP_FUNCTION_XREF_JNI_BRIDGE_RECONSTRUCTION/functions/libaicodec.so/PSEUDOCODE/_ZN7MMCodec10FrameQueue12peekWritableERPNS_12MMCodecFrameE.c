// Function: MMCodec::FrameQueue::peekWritable(MMCodec::MMCodecFrame*&)
// RVA: 0x1541c8, Size: 520 bytes
int64_t _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x154208
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x154234
    pthread_self(...); // call imported API via PLT at 0x15429c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_7f6cb = "peekWritable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1542c8
    pthread_self(...); // call imported API via PLT at 0x1542ec
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_7f6cb = "peekWritable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x154314
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x154344
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154374
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1543b0
    __stack_chk_fail(...); // call imported API via PLT at 0x1543cc
}
