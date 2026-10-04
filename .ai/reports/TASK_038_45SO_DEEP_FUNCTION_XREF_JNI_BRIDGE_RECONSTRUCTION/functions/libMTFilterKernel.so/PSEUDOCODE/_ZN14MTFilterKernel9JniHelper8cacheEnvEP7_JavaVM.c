// Function: MTFilterKernel::JniHelper::cacheEnv(_JavaVM*)
// RVA: 0xc27ac, Size: 280 bytes
int64_t _ZN14MTFilterKernel9JniHelper8cacheEnvEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    pthread_setspecific(...); // call PLT API at 0xc2828
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2834
    const char* str = "FilterKernel";
    const char* str = "JNI interface version 1.4 not supported";
    __android_log_print(...); // call PLT API at 0xc2854
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2858
    const char* str = "FilterKernel";
    const char* str = "Failed to get the environment using GetEnv()";
    __android_log_print(...); // call PLT API at 0xc2878
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc28a0
    const char* str = "FilterKernel";
    const char* str = "Failed to get the environment using AttachCurrentThread()";
    __stack_chk_fail(...); // call PLT API at 0xc28c0
}
