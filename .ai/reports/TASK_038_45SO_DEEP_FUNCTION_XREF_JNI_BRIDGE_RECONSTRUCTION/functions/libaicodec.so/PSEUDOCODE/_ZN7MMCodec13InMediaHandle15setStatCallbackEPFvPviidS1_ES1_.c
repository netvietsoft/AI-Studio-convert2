// Function: MMCodec::InMediaHandle::setStatCallback(void (*)(void*, int, int, double, void*), void*)
// RVA: 0x143a64, Size: 212 bytes
int64_t _ZN7MMCodec13InMediaHandle15setStatCallbackEPFvPviidS1_ES1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext15setStatCallbackEPFvPviidS1_ES1_(...); // call imported API via PLT at 0x143a84
    pthread_self(...); // call imported API via PLT at 0x143aa8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c3df = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> HandleCtx is null!"; // string xref
    const char* s_6eae2 = "setStatCallback"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x143ad4
    pthread_self(...); // call imported API via PLT at 0x143af8
    const char* s_83883 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> HandleCtx is null!
"; // string xref
    const char* s_6eae2 = "setStatCallback"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143b28
    return a0;
}
