// Function: MTFilterKernel::CMTDynamicFilter::BindFBO(int, int)
// RVA: 0x11dca0, Size: 488 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x11dcd0
    glFramebufferTexture2D(...); // call PLT API at 0x11dce8
    glCheckFramebufferStatus(...); // call PLT API at 0x11dcf0
    return a0;
    glDeleteTextures(...); // call PLT API at 0x11dd58
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11dd70
    glGenFramebuffers(...); // call PLT API at 0x11dd8c
    glBindFramebuffer(...); // call PLT API at 0x11dd9c
    glFramebufferTexture2D(...); // call PLT API at 0x11ddb8
    glCheckFramebufferStatus(...); // call PLT API at 0x11ddc0
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11ddec
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x11de10
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11de2c
    const char* str = "FilterKernel";
    const char* str = "ERROR: create texture failed,m_FrameBufferTexture == 0";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11de4c
    const char* str = "FilterKernel";
    const char* str = "ERROR: gen fbo failed,m_FilterFrameBuffer == 0";
    __android_log_print(...); // call PLT API at 0x11de6c
    return a0;
}
