// Function: MMCodec::FrameQueue::peekReadable(int, int)
// RVA: 0x1544a8, Size: 592 bytes
int64_t _ZN7MMCodec10FrameQueue12peekReadableEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1544ec
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0x154518
    _ZNSt6__ndk16chrono12system_clock3nowEv(...); // call imported API via PLT at 0x15451c
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x154554
    pthread_self(...); // call imported API via PLT at 0x154598
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_73400 = "peekReadable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1545c4
    pthread_self(...); // call imported API via PLT at 0x1545e8
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_73400 = "peekReadable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x154610
    _ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE(...); // call imported API via PLT at 0x154678
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0x15467c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1546c8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1546f4
}
