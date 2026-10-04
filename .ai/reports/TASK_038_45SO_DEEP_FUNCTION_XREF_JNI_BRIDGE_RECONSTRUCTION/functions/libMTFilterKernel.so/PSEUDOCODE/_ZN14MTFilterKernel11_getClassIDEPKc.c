// Function: MTFilterKernel::_getClassID(char const*)
// RVA: 0xc257c, Size: 252 bytes
int64_t _ZN14MTFilterKernel11_getClassIDEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call PLT API at 0xc259c
    _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(...); // call internal at 0xc25b4
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc25f4
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2600
    const char* str = "FilterKernel";
    const char* str = "Classloader failed to find class of %s";
    __android_log_print(...); // call PLT API at 0xc2624
    (*x8)(...);
    (*x8)(...);
    return a0;
    return a0;
}
