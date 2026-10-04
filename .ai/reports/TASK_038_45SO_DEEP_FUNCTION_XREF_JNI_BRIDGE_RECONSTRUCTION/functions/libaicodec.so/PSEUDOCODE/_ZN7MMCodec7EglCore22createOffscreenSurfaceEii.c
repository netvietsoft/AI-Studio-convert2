// Function: MMCodec::EglCore::createOffscreenSurface(int, int)
// RVA: 0x10f284, Size: 256 bytes
int64_t _ZN7MMCodec7EglCore22createOffscreenSurfaceEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglCreatePbufferSurface(...); // call imported API via PLT at 0x10f2c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e6dd = "[%s(%d)]:> eglCreatePbufferSurface error"; // string xref
    const char* s_764c3 = "createOffscreenSurface"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10f314
    const char* s_7f05b = "%s/MTMV_AICodec: [%s(%d)]:> eglCreatePbufferSurface error
"; // string xref
    const char* s_764c3 = "createOffscreenSurface"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f358
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10f380
}
