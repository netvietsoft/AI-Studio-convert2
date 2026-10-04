// Function: MTFilterKernel::CMTDynamicFilter::bindFBO(int, int, unsigned int&, unsigned int&)
// RVA: 0x11ee8c, Size: 308 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11eeb0
    glGenFramebuffers(...); // call PLT API at 0x11eecc
    glBindFramebuffer(...); // call PLT API at 0x11eedc
    glFramebufferTexture2D(...); // call PLT API at 0x11eef4
    glCheckFramebufferStatus(...); // call PLT API at 0x11eefc
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11ef20
    const char* str = "FilterKernel";
    const char* str = "[xiaoxw]--Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0x11ef44
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11ef58
    const char* str = "FilterKernel";
    const char* str = "m_CompyTexture is 0";
    __android_log_print(...); // call PLT API at 0x11ef78
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11ef8c
    const char* str = "FilterKernel";
    const char* str = "m_FilterFrameBuffer == 0";
    __android_log_print(...); // call PLT API at 0x11efac
    return a0;
}
