// Function: MTFilterKernel::MTlabFilterKernelRender::setFilterStatusAtIndex(bool, int)
// RVA: 0x1a8ea4, Size: 172 bytes
int64_t _ZN14MTFilterKernel23MTlabFilterKernelRender22setFilterStatusAtIndexEbi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x1a8ed8
    pthread_mutex_unlock(...); // call PLT API at 0x1a8ee8
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1a8f04
    const char* str = "FilterKernel";
    const char* str = "Failed to MTlabFilterKernelRender::setFilterStatusAtName : i:%d is out range of filters size:%d";
    __android_log_print(...); // call PLT API at 0x1a8f34
    return a0;
}
