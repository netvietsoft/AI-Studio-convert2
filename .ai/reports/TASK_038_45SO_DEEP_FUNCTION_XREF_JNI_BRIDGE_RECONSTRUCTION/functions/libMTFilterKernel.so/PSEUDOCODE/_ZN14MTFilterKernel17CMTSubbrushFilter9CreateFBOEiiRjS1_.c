// Function: MTFilterKernel::CMTSubbrushFilter::CreateFBO(int, int, unsigned int&, unsigned int&)
// RVA: 0x12bad8, Size: 224 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter9CreateFBOEiiRjS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x12baf8
    glGenFramebuffers(...); // call PLT API at 0x12bb10
    glBindFramebuffer(...); // call PLT API at 0x12bb1c
    glFramebufferTexture2D(...); // call PLT API at 0x12bb34
    glCheckFramebufferStatus(...); // call PLT API at 0x12bb3c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x12bb50
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x12bb74
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x12bb7c
    const char* str = "FilterKernel";
    const char* str = "ERROR: create texture failed,m_FrameBufferTexture == 0";
    __android_log_print(...); // call PLT API at 0x12bb9c
    return a0;
}
