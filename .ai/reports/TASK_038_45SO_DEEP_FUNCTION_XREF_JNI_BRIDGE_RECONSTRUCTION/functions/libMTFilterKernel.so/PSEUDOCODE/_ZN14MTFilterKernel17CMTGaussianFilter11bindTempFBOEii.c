// Function: MTFilterKernel::CMTGaussianFilter::bindTempFBO(int, int)
// RVA: 0x1207e0, Size: 380 bytes
int64_t _ZN14MTFilterKernel17CMTGaussianFilter11bindTempFBOEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call PLT API at 0x12082c
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x120844
    glGenFramebuffers(...); // call PLT API at 0x120860
    glBindFramebuffer(...); // call PLT API at 0x120870
    glFramebufferTexture2D(...); // call PLT API at 0x12088c
    glCheckFramebufferStatus(...); // call PLT API at 0x120894
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1208c0
    const char* str = "FilterKernel";
    const char* str = "Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0x1208e4
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x120900
    const char* str = "FilterKernel";
    const char* str = "mTempTexture =0";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x120920
    const char* str = "FilterKernel";
    const char* str = "m_FilterFrameBuffer == 0";
    __android_log_print(...); // call PLT API at 0x120940
    return a0;
}
