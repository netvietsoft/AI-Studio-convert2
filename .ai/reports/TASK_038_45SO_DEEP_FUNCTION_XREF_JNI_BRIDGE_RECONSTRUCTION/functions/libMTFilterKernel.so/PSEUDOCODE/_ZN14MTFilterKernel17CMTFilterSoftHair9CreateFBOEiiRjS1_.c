// Function: MTFilterKernel::CMTFilterSoftHair::CreateFBO(int, int, unsigned int&, unsigned int&)
// RVA: 0x1347ac, Size: 224 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x1347cc
    glGenFramebuffers(...); // call PLT API at 0x1347e4
    glBindFramebuffer(...); // call PLT API at 0x1347f0
    glFramebufferTexture2D(...); // call PLT API at 0x134808
    glCheckFramebufferStatus(...); // call PLT API at 0x134810
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x134824
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x134848
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x134850
    const char* str = "FilterKernel";
    const char* str = "ERROR: create texture failed,m_FrameBufferTexture == 0";
    __android_log_print(...); // call PLT API at 0x134870
    return a0;
}
