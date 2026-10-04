// Function: MMCodec::EglCore::makeCurrent(void*, void*)
// RVA: 0x10f4d4, Size: 384 bytes
int64_t _ZN7MMCodec7EglCore11makeCurrentEPvS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_7df3f = "[%s(%d)]:> NOTE: makeCurrent w/o display"; // string xref
    const char* s_8e9ed = "makeCurrent"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    __android_log_print(...); // call imported API via PLT at 0x10f53c
    const char* s_7cce6 = "%s/MTMV_AICodec: [%s(%d)]:> NOTE: makeCurrent w/o display
"; // string xref
    const char* s_8e9ed = "makeCurrent"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f590
    eglMakeCurrent(...); // call imported API via PLT at 0x10f5a0
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d54e = "[%s(%d)]:> [%d]egl make current failed"; // string xref
    const char* s_8e9ed = "makeCurrent"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10f5fc
    const char* s_71874 = "%s/MTMV_AICodec: [%s(%d)]:> [%d]egl make current failed
"; // string xref
    const char* s_8e9ed = "makeCurrent"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10f63c
    return a0;
}
