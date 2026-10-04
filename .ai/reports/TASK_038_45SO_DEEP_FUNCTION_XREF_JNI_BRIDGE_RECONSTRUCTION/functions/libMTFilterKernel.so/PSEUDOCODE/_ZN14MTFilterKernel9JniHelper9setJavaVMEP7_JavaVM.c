// Function: MTFilterKernel::JniHelper::setJavaVM(_JavaVM*)
// RVA: 0xc2744, Size: 104 bytes
int64_t _ZN14MTFilterKernel9JniHelper9setJavaVMEP7_JavaVM(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc2754
    pthread_self(...); // call PLT API at 0xc2760
    const char* str = "FilterKernel";
    const char* str = "JniHelper::setJavaVM(%p), pthread_self() = %ld";
    __android_log_print(...); // call PLT API at 0xc2780
    pthread_key_create(...); // call PLT API at 0xc27a8
}
