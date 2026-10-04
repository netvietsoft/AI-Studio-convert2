// Function: MMDetectionPlugin::_getClassID(char const*)
// RVA: 0x3f798, Size: 264 bytes
int64_t _ZN17MMDetectionPlugin11_getClassIDEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x3f7b8
    _ZN17MMDetectionPlugin9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x3f7d0
    (*x8)(...); // indirect call at 0x3f7e8
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x3f810
    const char* s_30045 = "MTMVCore";
    const char* s_2f8c8 = "[%s(%d)]:> Classloader failed to find class of %s
"; // string xref
    const char* s_3055f = "_getClassID"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x3f85c
    (*x8)(...); // indirect call at 0x3f86c
    (*x8)(...); // indirect call at 0x3f880
    return a0;
}
