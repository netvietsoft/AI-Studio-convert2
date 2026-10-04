// Function: MTFilterKernel::CMTDynamicFilter::BindFBO(unsigned int)
// RVA: 0x11e580, Size: 216 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x11e5a4
    glBindFramebuffer(...); // call PLT API at 0x11e5b8
    glFramebufferTexture2D(...); // call PLT API at 0x11e5d0
    glCheckFramebufferStatus(...); // call PLT API at 0x11e5d8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11e5ec
    const char* str = "FilterKernel";
    const char* str = "CMTDynamicFilter::BindFBO(%u)::Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0x11e61c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11e620
    const char* str = "FilterKernel";
    const char* str = "CMTDynamicFilter could not create framebuffer";
    __android_log_print(...); // call PLT API at 0x11e648
    return a0;
}
