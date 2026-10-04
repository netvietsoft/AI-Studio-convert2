// Function: MTFilterKernel::_detachCurrentThread(void*)
// RVA: 0xc26ac, Size: 80 bytes
int64_t _ZN14MTFilterKernel20_detachCurrentThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xc26b4
    pthread_self(...); // call PLT API at 0xc26c0
    const char* str = "FilterKernel";
    const char* str = "JniHelper::getJavaVM(), pthread_self() = %ld";
    __android_log_print(...); // call PLT API at 0xc26dc
}
