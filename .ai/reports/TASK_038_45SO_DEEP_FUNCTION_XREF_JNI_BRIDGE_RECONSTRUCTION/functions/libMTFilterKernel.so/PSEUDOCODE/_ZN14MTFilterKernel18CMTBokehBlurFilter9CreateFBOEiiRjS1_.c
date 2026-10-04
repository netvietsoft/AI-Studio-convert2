// Function: MTFilterKernel::CMTBokehBlurFilter::CreateFBO(int, int, unsigned int&, unsigned int&)
// RVA: 0x122ca8, Size: 224 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter9CreateFBOEiiRjS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x122cc8
    glGenFramebuffers(...); // call PLT API at 0x122ce0
    glBindFramebuffer(...); // call PLT API at 0x122cec
    glFramebufferTexture2D(...); // call PLT API at 0x122d04
    glCheckFramebufferStatus(...); // call PLT API at 0x122d0c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x122d20
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x122d44
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x122d4c
    const char* str = "FilterKernel";
    const char* str = "ERROR: create texture failed,m_FrameBufferTexture == 0";
    __android_log_print(...); // call PLT API at 0x122d6c
    return a0;
}
