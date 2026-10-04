// Function: MTFilterKernel::JniHelper::getMethodInfo(MTFilterKernel::JniMethodInfo_&, char const*, char const*, char const*)
// RVA: 0xc2afc, Size: 264 bytes
int64_t _ZN14MTFilterKernel9JniHelper13getMethodInfoERNS_14JniMethodInfo_EPKcS4_S4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xc2b3c
    _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(...); // call internal at 0xc2b54
    (*x8)(...);
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2bb0
    const char* str = "FilterKernel";
    const char* str = "Failed to find method id of %s, paramCode: %s";
    __android_log_print(...); // call PLT API at 0xc2bd8
    (*x8)(...);
    return a0;
}
