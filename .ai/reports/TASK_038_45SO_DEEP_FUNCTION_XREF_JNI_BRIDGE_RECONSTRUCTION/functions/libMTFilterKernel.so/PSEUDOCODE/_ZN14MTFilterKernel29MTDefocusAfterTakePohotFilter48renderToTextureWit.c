// Function: MTFilterKernel::MTDefocusAfterTakePohotFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xdaa00, Size: 932 bytes
int64_t _ZN14MTFilterKernel29MTDefocusAfterTakePohotFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer10byteBufferEv(...); // call internal at 0xdaa88
    _ZN14MTFilterKernel11DefocusStep3RunEPhiiS1_iiPvPNS0_6ConfigEb(...); // call internal at 0xdaaf4
    glBindTexture(...); // call PLT API at 0xdab28
    glTexImage2D(...); // call PLT API at 0xdab50
    glTexParameterf(...); // call PLT API at 0xdab6c
    glTexParameterf(...); // call PLT API at 0xdab7c
    glTexParameteri(...); // call PLT API at 0xdab8c
    glTexParameteri(...); // call PLT API at 0xdab9c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xdabac
    const char* str = "FilterKernel";
    __android_log_print(...); // call PLT API at 0xdabcc
    glDeleteTextures(...); // call PLT API at 0xdabfc
    glDeleteFramebuffers(...); // call PLT API at 0xdac10
    (*x8)(...);
    _ZN14MTFilterKernel7GLUtils16LoadTexture_BYTEEPhiij(...); // call internal at 0xdac40
    glGenFramebuffers(...); // call PLT API at 0xdac50
    glBindFramebuffer(...); // call PLT API at 0xdac5c
    glBindTexture(...); // call PLT API at 0xdac68
    glFramebufferTexture2D(...); // call PLT API at 0xdac80
    glCheckFramebufferStatus(...); // call PLT API at 0xdac88
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xdac9c
    const char* str = "FilterKernel";
    const char* str = "ERROR: Incomplete filter FBO 1: %d; framebuffer size = %d, %d";
    __android_log_print(...); // call PLT API at 0xdacc8
    _Znwm(...); // call PLT API at 0xdacd0
    _ZN14MTFilterKernel19GPUImageFramebufferC2EPNS_15GPUImageContextENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xdad10
    _ZdaPv(...); // call PLT API at 0xdad28
    _ZN14MTFilterKernel12MTFilterBase15copyFramebufferEPNS_15GPUImageContextEPNS_19GPUImageFramebufferES4_(...); // call internal at 0xdad38
    return a0;
    _ZdlPv(...); // call PLT API at 0xdad80
    sub_1B0544(...); // call internal at 0xdad9c
    __stack_chk_fail(...); // call PLT API at 0xdada0
}
