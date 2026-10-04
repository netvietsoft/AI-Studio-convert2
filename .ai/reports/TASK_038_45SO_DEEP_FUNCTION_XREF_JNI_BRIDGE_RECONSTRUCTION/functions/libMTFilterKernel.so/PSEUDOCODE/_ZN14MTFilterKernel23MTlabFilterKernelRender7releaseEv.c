// Function: MTFilterKernel::MTlabFilterKernelRender::release()
// RVA: 0x1a683c, Size: 732 bytes
int64_t _ZN14MTFilterKernel23MTlabFilterKernelRender7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel20MTOnlineFilterRender7releaseEv(...); // call internal at 0x1a6854
    (*x8)(...);
    (*x8)(...);
    pthread_mutex_lock(...); // call PLT API at 0x1a68a0
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    pthread_mutex_unlock(...); // call PLT API at 0x1a6a0c
    _ZN14MTFilterKernel15GPUImageContext7releaseEv(...); // call internal at 0x1a6a1c
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1a6a98
    const char* str = "FilterKernel";
    const char* str = "release MTlabFilterKernelRender %p";
    __android_log_print(...); // call PLT API at 0x1a6ac8
    _ZdlPv(...); // call PLT API at 0x1a6ad0
    _ZdlPv(...); // call PLT API at 0x1a6af0
    _ZdlPv(...); // call PLT API at 0x1a6b00
    return a0;
}
