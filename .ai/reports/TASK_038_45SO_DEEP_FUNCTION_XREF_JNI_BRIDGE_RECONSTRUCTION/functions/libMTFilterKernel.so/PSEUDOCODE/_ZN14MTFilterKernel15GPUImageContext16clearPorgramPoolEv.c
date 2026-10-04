// Function: MTFilterKernel::GPUImageContext::clearPorgramPool()
// RVA: 0x15e36c, Size: 180 bytes
int64_t _ZN14MTFilterKernel15GPUImageContext16clearPorgramPoolEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x15e388
    sub_15FD78(...); // call internal at 0x15e3a8
    pthread_mutex_unlock(...); // call PLT API at 0x15e3c8
    _ZN14MTFilterKernel15GPUImageProgramD2Ev(...); // call internal at 0x15e3e4
    _ZdlPv(...); // call PLT API at 0x15e3ec
}
