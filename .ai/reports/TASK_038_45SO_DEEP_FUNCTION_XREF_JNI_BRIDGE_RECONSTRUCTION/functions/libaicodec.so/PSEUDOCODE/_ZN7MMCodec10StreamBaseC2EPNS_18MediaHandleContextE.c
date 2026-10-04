// Function: MMCodec::StreamBase::StreamBase(MMCodec::MediaHandleContext*)
// RVA: 0x151054, Size: 556 bytes
int64_t _ZN7MMCodec10StreamBaseC2EPNS_18MediaHandleContextE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202010 = (void*)0x202010; // global ref
    _Znwm(...); // call imported API via PLT at 0x1510e4
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x1510f0
    _ZN7MMCodec12MMCodecFrameC1EPNS_14AICodecContextE(...); // call imported API via PLT at 0x1510fc
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x15115c
    pthread_self(...); // call imported API via PLT at 0x151184
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ecf9 = "[%s(%d)]:> [StreamBase(%p)](%ld):> !!! alloc av frame failed"; // string xref
    const char* s_67f44 = "StreamBase"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1511b0
    pthread_self(...); // call imported API via PLT at 0x1511d4
    const char* s_906c9 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> !!! alloc av frame failed
"; // string xref
    const char* s_67f44 = "StreamBase"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1511fc
    return a0;
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x15121c
    sub_151280(...); // call internal func at 0x151230
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x151238
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x151240
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0x151248
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x151250
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x151258
    _ZdlPv(...); // call imported API via PLT at 0x15126c
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x151274
}
