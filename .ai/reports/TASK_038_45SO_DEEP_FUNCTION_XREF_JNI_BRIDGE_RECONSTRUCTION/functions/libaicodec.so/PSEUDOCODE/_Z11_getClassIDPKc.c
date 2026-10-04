// Function: _getClassID(char const*)
// RVA: 0x1048d4, Size: 344 bytes
int64_t _Z11_getClassIDPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x1048f4
    _ZN9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x10490c
    (*x8)(...); // indirect call at 0x104924
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x10494c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_716a5 = "[%s(%d)]:> Classloader failed to find class of %s"; // string xref
    const char* s_77d59 = "_getClassID"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x104998
    const char* s_6f707 = "%s/MTMV_AICodec: [%s(%d)]:> Classloader failed to find class of %s
"; // string xref
    const char* s_77d59 = "_getClassID"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1049d8
    (*x8)(...); // indirect call at 0x1049e8
    (*x8)(...); // indirect call at 0x1049fc
    return a0;
    return a0;
}
