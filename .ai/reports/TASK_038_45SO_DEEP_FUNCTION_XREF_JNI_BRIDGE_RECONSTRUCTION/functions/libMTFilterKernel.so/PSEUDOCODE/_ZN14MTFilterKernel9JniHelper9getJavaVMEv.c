// Function: MTFilterKernel::JniHelper::getJavaVM()
// RVA: 0xc26fc, Size: 72 bytes
int64_t _ZN14MTFilterKernel9JniHelper9getJavaVMEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2704
    pthread_self(...); // call PLT API at 0xc2710
    const char* str = "FilterKernel";
    const char* str = "JniHelper::getJavaVM(), pthread_self() = %ld";
    __android_log_print(...); // call PLT API at 0xc272c
    return a0;
}
