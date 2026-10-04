// Function: MTFilterKernel::JniHelper::getStaticMethodInfo(MTFilterKernel::JniMethodInfo_&, char const*, char const*, char const*)
// RVA: 0xc28cc, Size: 300 bytes
int64_t _ZN14MTFilterKernel9JniHelper19getStaticMethodInfoERNS_14JniMethodInfo_EPKcS4_S4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xc290c
    _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(...); // call internal at 0xc2924
    (*x8)(...);
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2980
    const char* str = "FilterKernel";
    const char* str = "Failed to find static method id of %s";
    __android_log_print(...); // call PLT API at 0xc29a4
    (*x8)(...);
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc29d0
    const char* str = "FilterKernel";
    const char* str = "Failed to get JNIEnv";
    __android_log_print(...); // call PLT API at 0xc29f0
}
