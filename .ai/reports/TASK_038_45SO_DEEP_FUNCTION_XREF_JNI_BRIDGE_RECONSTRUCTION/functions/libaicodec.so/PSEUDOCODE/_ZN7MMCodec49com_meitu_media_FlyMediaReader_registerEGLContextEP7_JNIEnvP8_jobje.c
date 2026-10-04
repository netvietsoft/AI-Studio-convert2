// Function: MMCodec::com_meitu_media_FlyMediaReader_registerEGLContext(_JNIEnv*, _jobject*, long)
// RVA: 0x106584, Size: 204 bytes
int64_t _ZN7MMCodec49com_meitu_media_FlyMediaReader_registerEGLContextEP7_JNIEnvP8_jobjectl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentContext(...); // call imported API via PLT at 0x106598
    _ZN7MMCodec13MTMediaReader17getAICodecContextEv(...); // call imported API via PLT at 0x1065a4
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv(...); // call imported API via PLT at 0x1065ac
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ca85 = "[%s(%d)]:> get nativeObject error"; // string xref
    const char* s_6ab95 = "com_meitu_media_FlyMediaReader_registerEGLContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x106600
    const char* s_80c06 = "%s/MTMV_AICodec: [%s(%d)]:> get nativeObject error
"; // string xref
    const char* s_6ab95 = "com_meitu_media_FlyMediaReader_registerEGLContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10663c
    return a0;
}
