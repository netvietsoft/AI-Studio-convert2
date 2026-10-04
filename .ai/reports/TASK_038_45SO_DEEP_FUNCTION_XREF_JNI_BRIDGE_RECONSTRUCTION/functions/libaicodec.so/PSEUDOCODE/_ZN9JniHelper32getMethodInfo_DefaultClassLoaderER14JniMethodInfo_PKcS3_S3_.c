// Function: JniHelper::getMethodInfo_DefaultClassLoader(JniMethodInfo_&, char const*, char const*, char const*)
// RVA: 0x105148, Size: 480 bytes
int64_t _ZN9JniHelper32getMethodInfo_DefaultClassLoaderER14JniMethodInfo_PKcS3_S3_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x105188
    _ZN9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x1051a0
    (*x8)(...); // indirect call at 0x1051bc
    (*x8)(...); // indirect call at 0x1051e0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77d65 = "[%s(%d)]:> Failed to find class %s"; // string xref
    const char* s_6778d = "getMethodInfo_DefaultClassLoader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10523c
    const char* s_68826 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to find class %s
"; // string xref
    const char* s_6778d = "getMethodInfo_DefaultClassLoader"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80b9a = "[%s(%d)]:> Failed to find method id of %s"; // string xref
    const char* s_6778d = "getMethodInfo_DefaultClassLoader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1052bc
    const char* s_8a153 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to find method id of %s
"; // string xref
    const char* s_6778d = "getMethodInfo_DefaultClassLoader"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1052fc
    (*x8)(...); // indirect call at 0x10530c
    return a0;
}
