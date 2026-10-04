// Function: MMCodec::EglCore::makeNothingCurrent()
// RVA: 0x10f654, Size: 220 bytes
int64_t _ZN7MMCodec7EglCore18makeNothingCurrentEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglMakeCurrent(...); // call imported API via PLT at 0x10f66c
    return a0;
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d54e = "[%s(%d)]:> [%d]egl make current failed"; // string xref
    const char* s_80dcf = "makeNothingCurrent"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10f6e0
    const char* s_71874 = "%s/MTMV_AICodec: [%s(%d)]:> [%d]egl make current failed
"; // string xref
    const char* s_80dcf = "makeNothingCurrent"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f720
    return a0;
}
