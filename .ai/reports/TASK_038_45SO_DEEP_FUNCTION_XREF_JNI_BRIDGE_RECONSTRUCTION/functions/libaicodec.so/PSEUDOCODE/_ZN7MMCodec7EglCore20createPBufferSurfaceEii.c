// Function: MMCodec::EglCore::createPBufferSurface(int, int)
// RVA: 0x10f184, Size: 256 bytes
int64_t _ZN7MMCodec7EglCore20createPBufferSurfaceEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglCreatePbufferSurface(...); // call imported API via PLT at 0x10f1c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e6dd = "[%s(%d)]:> eglCreatePbufferSurface error"; // string xref
    const char* s_6d539 = "createPBufferSurface"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10f214
    const char* s_7f05b = "%s/MTMV_AICodec: [%s(%d)]:> eglCreatePbufferSurface error
"; // string xref
    const char* s_6d539 = "createPBufferSurface"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f258
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10f280
}
