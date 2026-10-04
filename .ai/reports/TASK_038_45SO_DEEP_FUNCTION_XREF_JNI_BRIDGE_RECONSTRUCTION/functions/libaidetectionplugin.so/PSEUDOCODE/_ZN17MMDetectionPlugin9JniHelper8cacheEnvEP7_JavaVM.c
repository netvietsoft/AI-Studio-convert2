// Function: MMDetectionPlugin::JniHelper::cacheEnv(_JavaVM*)
// RVA: 0x3fad0, Size: 364 bytes
int64_t _ZN17MMDetectionPlugin9JniHelper8cacheEnvEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x3fb08
    (*x8)(...); // indirect call at 0x3fb38
    pthread_setspecific(...); // call imported API via PLT at 0x3fb4c
    const char* s_30045 = "MTMVCore";
    const char* s_308d5 = "[%s(%d)]:> JNI interface version 1.4 not supported
"; // string xref
    const char* s_2fbb4 = "cacheEnv"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x3fb94
    const char* s_30045 = "MTMVCore";
    const char* s_30ca2 = "[%s(%d)]:> Failed to get the environment using GetEnv()
"; // string xref
    const char* s_2fbb4 = "cacheEnv"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x3fbd4
    return a0;
    const char* s_30045 = "MTMVCore";
    const char* s_2f8fb = "[%s(%d)]:> Failed to get the environment using AttachCurrentThread()
"; // string xref
    const char* s_2fbb4 = "cacheEnv"; // string xref
    __stack_chk_fail(...); // call imported API via PLT at 0x3fc38
}
