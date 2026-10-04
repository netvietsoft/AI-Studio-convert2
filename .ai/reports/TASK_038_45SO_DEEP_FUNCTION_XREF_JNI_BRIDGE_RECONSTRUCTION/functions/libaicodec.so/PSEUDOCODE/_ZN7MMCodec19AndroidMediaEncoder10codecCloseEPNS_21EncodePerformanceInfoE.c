// Function: MMCodec::AndroidMediaEncoder::codecClose(MMCodec::EncodePerformanceInfo*)
// RVA: 0xf24e8, Size: 948 bytes
int64_t _ZN7MMCodec19AndroidMediaEncoder10codecCloseEPNS_21EncodePerformanceInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentContext(...); // call imported API via PLT at 0xf251c
    eglGetCurrentDisplay(...); // call imported API via PLT at 0xf2528
    eglGetCurrentSurface(...); // call imported API via PLT at 0xf2534
    eglGetCurrentSurface(...); // call imported API via PLT at 0xf2540
    glGetIntegerv(...); // call imported API via PLT at 0xf2550
    glGetIntegerv(...); // call imported API via PLT at 0xf255c
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf2560
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf2578
    (*x8)(...); // indirect call at 0xf2598
    _ZN7MMCodec10ThreadPoolD1Ev(...); // call imported API via PLT at 0xf25a8
    _ZdlPv(...); // call imported API via PLT at 0xf25b0
    _ZN7MMCodec14EglSurfaceBase11makeCurrentEv(...); // call imported API via PLT at 0xf25c4
    _ZN7MMCodec14AndroidEncoder10codecCloseEPNS_21EncodePerformanceInfoE(...); // call imported API via PLT at 0xf25d8
    ANativeWindow_release(...); // call imported API via PLT at 0xf25ec
    (*x8)(...); // indirect call at 0xf2608
    (*x8)(...); // indirect call at 0xf2624
    (*x8)(...); // indirect call at 0xf2640
    _ZN7MMCodec8GLShaderD1Ev(...); // call imported API via PLT at 0xf2654
    _ZdlPv(...); // call imported API via PLT at 0xf265c
    (*x8)(...); // indirect call at 0xf2670
    eglMakeCurrent(...); // call imported API via PLT at 0xf2688
    glBindFramebuffer(...); // call imported API via PLT at 0xf2698
    glViewport(...); // call imported API via PLT at 0xf26a4
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90bfe = "[%s(%d)]:> [%s:%d]state error"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf2708
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_674b0 = "%s/MTMV_AICodec: [%s(%d)]:> [%s:%d]state error
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf274c
    return a0;
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82f20 = "[%s(%d)]:> [%s] m_pWinSurface->makeCurrent() failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf27c4
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_7ed08 = "%s/MTMV_AICodec: [%s(%d)]:> [%s] m_pWinSurface->makeCurrent() failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf2804
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_712eb = "[%s(%d)]:> [%s:%d]egl make current failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf2850
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_8f94c = "%s/MTMV_AICodec: [%s(%d)]:> [%s:%d]egl make current failed
"; // string xref
    __stack_chk_fail(...); // call imported API via PLT at 0xf2898
}
