// Function: MMCodec::EglCore::createWindowSurface(ANativeWindow*)
// RVA: 0x10f090, Size: 244 bytes
int64_t _ZN7MMCodec7EglCore19createWindowSurfaceEP13ANativeWindow(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglCreateWindowSurface(...); // call imported API via PLT at 0x10f0c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72c1a = "[%s(%d)]:> eglCreateWindowSurface error"; // string xref
    const char* s_74fe9 = "createWindowSurface"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10f114
    const char* s_790d9 = "%s/MTMV_AICodec: [%s(%d)]:> eglCreateWindowSurface error
"; // string xref
    const char* s_74fe9 = "createWindowSurface"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f158
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10f180
}
