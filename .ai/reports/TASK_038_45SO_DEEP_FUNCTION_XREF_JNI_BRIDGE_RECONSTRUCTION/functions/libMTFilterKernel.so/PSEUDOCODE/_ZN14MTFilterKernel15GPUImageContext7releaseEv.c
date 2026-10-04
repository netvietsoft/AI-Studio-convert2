// Function: MTFilterKernel::GPUImageContext::release()
// RVA: 0x15e234, Size: 312 bytes
int64_t _ZN14MTFilterKernel15GPUImageContext7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageContext16clearPorgramPoolEv(...); // call internal at 0x15e248
    _ZN14MTFilterKernel15GPUImageContext20clearFramebufferPoolEv(...); // call internal at 0x15e250
    sub_F9EDC(...); // call internal at 0x15e26c
    pthread_mutex_lock(...); // call PLT API at 0x15e27c
    sub_15FE28(...); // call internal at 0x15e298
    pthread_mutex_unlock(...); // call PLT API at 0x15e2a8
    _ZN14MTFilterKernel15GPUImageContext14clearMeshIndexEv(...); // call internal at 0x15e2bc
    glDeleteRenderbuffers(...); // call PLT API at 0x15e2e0
    (*x8)(...);
}
