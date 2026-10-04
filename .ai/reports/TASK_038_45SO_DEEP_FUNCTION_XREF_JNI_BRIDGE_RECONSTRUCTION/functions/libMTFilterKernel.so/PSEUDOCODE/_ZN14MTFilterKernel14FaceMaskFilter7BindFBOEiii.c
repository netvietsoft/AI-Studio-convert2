// Function: MTFilterKernel::FaceMaskFilter::BindFBO(int, int, int)
// RVA: 0x11f9e4, Size: 744 bytes
int64_t _ZN14MTFilterKernel14FaceMaskFilter7BindFBOEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call PLT API at 0x11fa5c
    glDeleteTextures(...); // call PLT API at 0x11fa74
    glDeleteTextures(...); // call PLT API at 0x11fa8c
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11fa9c
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11faac
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11fabc
    glGenFramebuffers(...); // call PLT API at 0x11fb00
    glBindFramebuffer(...); // call PLT API at 0x11fb10
    glFramebufferTexture2D(...); // call PLT API at 0x11fb30
    glCheckFramebufferStatus(...); // call PLT API at 0x11fb3c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11fb50
    const char* str = "FilterKernel";
    const char* str = "ERROR: create texture failed,m_FrameBufferTexture == 0";
    glGenFramebuffers(...); // call PLT API at 0x11fb84
    glBindFramebuffer(...); // call PLT API at 0x11fb94
    glFramebufferTexture2D(...); // call PLT API at 0x11fbb4
    glCheckFramebufferStatus(...); // call PLT API at 0x11fbc0
    return a0;
    glGenFramebuffers(...); // call PLT API at 0x11fbfc
    glBindFramebuffer(...); // call PLT API at 0x11fc0c
    glFramebufferTexture2D(...); // call PLT API at 0x11fc2c
    glCheckFramebufferStatus(...); // call PLT API at 0x11fc38
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11fc4c
    const char* str = "FilterKernel";
    const char* str = "ERROR: bind FrameBuffer error ID = %d %d";
    __android_log_print(...); // call PLT API at 0x11fc74
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11fc90
    const char* str = "FilterKernel";
    const char* str = "ERROR: gen fbo failed,m_FilterFrameBuffer == 0";
    __android_log_print(...); // call PLT API at 0x11fcb0
    return a0;
}
