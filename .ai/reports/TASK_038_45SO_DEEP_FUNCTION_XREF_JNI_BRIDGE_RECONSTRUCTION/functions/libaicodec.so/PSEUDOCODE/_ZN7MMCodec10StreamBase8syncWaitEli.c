// Function: MMCodec::StreamBase::syncWait(long, int)
// RVA: 0x1517ac, Size: 768 bytes
int64_t _ZN7MMCodec10StreamBase8syncWaitEli(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1517e0
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x151824
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x151830
    void* g_202010 = (void*)0x202010; // global ref
    _ZN7MMCodec10FrameQueue8syncWaitEliNSt6__ndk18functionIFbllEEE(...); // call imported API via PLT at 0x151870
    pthread_self(...); // call imported API via PLT at 0x1518b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89161 = "[%s(%d)]:> [StreamBase(%p)](%ld):> no init"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1518dc
    pthread_self(...); // call imported API via PLT at 0x151900
    const char* s_87a0d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> no init
"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x151928
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151934
    (*x8)(...); // indirect call at 0x15195c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151964
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1519b4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_783e1 = "[%s(%d)]:> [StreamBase(%p)](%ld):> can't get frame"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1519e0
    pthread_self(...); // call imported API via PLT at 0x151a04
    const char* s_6fe34 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> can't get frame
"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x151a2c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151a38
    __stack_chk_fail(...); // call imported API via PLT at 0x151a4c
    (*x9)(...); // indirect call at 0x151a80
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151a90
}
