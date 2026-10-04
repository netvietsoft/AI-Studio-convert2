// Function: MTFilterKernel::JniHelper::getMethodInfo_DefaultClassLoader(MTFilterKernel::JniMethodInfo_&, char const*, char const*, char const*)
// RVA: 0xc29f8, Size: 260 bytes
int64_t _ZN14MTFilterKernel9JniHelper32getMethodInfo_DefaultClassLoaderERNS_14JniMethodInfo_EPKcS4_S4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xc2a38
    _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(...); // call internal at 0xc2a50
    (*x8)(...);
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2aac
    const char* str = "FilterKernel";
    const char* str = "Failed to find method id of %s";
    __android_log_print(...); // call PLT API at 0xc2ad0
    (*x8)(...);
    return a0;
}
