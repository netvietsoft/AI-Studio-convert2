// Function: MTFilterKernel::CMTDynamicFilter::BindFBO(unsigned int, unsigned int)
// RVA: 0x11e658, Size: 148 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x11e674
    glFramebufferTexture2D(...); // call PLT API at 0x11e68c
    glCheckFramebufferStatus(...); // call PLT API at 0x11e694
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11e6a8
    const char* str = "FilterKernel";
    const char* str = "CMTDynamicFilter::BindFBO(%u)::Create FrameBuffer error. ID = %d";
    __android_log_print(...); // call PLT API at 0x11e6d0
    return a0;
}
