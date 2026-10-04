// Function: MMCodec::EglSurfaceBase::swapBuffers()
// RVA: 0x10fe34, Size: 176 bytes
int64_t _ZN7MMCodec14EglSurfaceBase11swapBuffersEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec7EglCore11swapBuffersEPv(...); // call imported API via PLT at 0x10fe4c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91155 = "[%s(%d)]:> WARNING: swapBuffers() failed"; // string xref
    const char* s_6ae06 = "swapBuffers"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10fe94
    const char* s_85df6 = "%s/MTMV_AICodec: [%s(%d)]:> WARNING: swapBuffers() failed
"; // string xref
    const char* s_6ae06 = "swapBuffers"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10fed0
    return a0;
}
