// Function: JniHelper::cacheEnv(_JavaVM*)
// RVA: 0x104cc0, Size: 544 bytes
int64_t _ZN9JniHelper8cacheEnvEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x104cf8
    (*x8)(...); // indirect call at 0x104d28
    pthread_setspecific(...); // call imported API via PLT at 0x104d3c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ddbc = "[%s(%d)]:> JNI interface version 1.4 not supported"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104d84
    const char* s_842d3 = "%s/MTMV_AICodec: [%s(%d)]:> JNI interface version 1.4 not supported
"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x104dc0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ce2f = "[%s(%d)]:> Failed to get the environment using GetEnv()"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104e00
    const char* s_88764 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to get the environment using GetEnv()
"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x104e3c
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8fb4e = "[%s(%d)]:> Failed to get the environment using AttachCurrentThread()"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104ea0
    const char* s_8fb93 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to get the environment using AttachCurrentThread()
"; // string xref
    const char* s_6ab4e = "cacheEnv"; // string xref
    __stack_chk_fail(...); // call imported API via PLT at 0x104edc
}
