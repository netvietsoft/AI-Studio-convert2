// Function: MMCodec::FrameQueue::syncWait(long, int, std::__ndk1::function<bool (long, long)>)
// RVA: 0x1548dc, Size: 920 bytes
int64_t _ZN7MMCodec10FrameQueue8syncWaitEliNSt6__ndk18functionIFbllEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15491c
    (*x8)(...); // indirect call at 0x154978
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x154994
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15499c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1549ac
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x1549b8
    (*x8)(...); // indirect call at 0x1549e0
    pthread_self(...); // call imported API via PLT at 0x154a0c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dac5 = "[%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x154a38
    pthread_self(...); // call imported API via PLT at 0x154a5c
    const char* s_76bbf = "%s/MTMV_AICodec: [%s(%d)]:> [FrameQueue(%p)](%ld):> FrameQueue didn't init!
"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x154a84
    (*x8)(...); // indirect call at 0x154aa8
    sub_154DB4(...); // call internal func at 0x154ab8
    (*x8)(...); // indirect call at 0x154ae4
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0x154af4
    _ZNSt6__ndk16chrono12system_clock3nowEv(...); // call imported API via PLT at 0x154af8
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x154b34
    _ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE(...); // call imported API via PLT at 0x154b90
    _ZNSt6__ndk16chrono12steady_clock3nowEv(...); // call imported API via PLT at 0x154b94
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154ba4
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x154bb0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154bbc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154bcc
    return a0;
    const char* s_8db00 = "unique_lock::unlock: not locked"; // string xref
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call imported API via PLT at 0x154c18
    sub_D867C(...); // call internal func at 0x154c2c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x154c54
    __stack_chk_fail(...); // call imported API via PLT at 0x154c70
}
