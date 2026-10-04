// Function: MMCodec::EglSurfaceBase::releaseEglSurface()
// RVA: 0x10fa58, Size: 188 bytes
int64_t _ZN7MMCodec14EglSurfaceBase17releaseEglSurfaceEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec7EglCore14releaseSurfaceEPv(...); // call imported API via PLT at 0x10fa74
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e60f = "[%s(%d)]:> end"; // string xref
    const char* s_8337a = "releaseEglSurface"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10fac0
    const char* s_85a40 = "%s/MTMV_AICodec: [%s(%d)]:> end
"; // string xref
    const char* s_8337a = "releaseEglSurface"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10fb04
    return a0;
}
