// Function: MTFilterKernel::GLFramebufferTexture::AsFrameBufferTexture(unsigned int, int, int)
// RVA: 0x13f358, Size: 168 bytes
int64_t _ZN14MTFilterKernel20GLFramebufferTexture20AsFrameBufferTextureEjii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x13f384
    glBindFramebuffer(...); // call PLT API at 0x13f390
    glFramebufferTexture2D(...); // call PLT API at 0x13f3a8
    glCheckFramebufferStatus(...); // call PLT API at 0x13f3b0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x13f3c4
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x13f3e8
    return a0;
}
