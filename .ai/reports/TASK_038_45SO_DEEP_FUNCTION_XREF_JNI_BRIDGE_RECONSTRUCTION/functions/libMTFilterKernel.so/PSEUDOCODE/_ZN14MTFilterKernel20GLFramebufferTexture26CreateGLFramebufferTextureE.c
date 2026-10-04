// Function: MTFilterKernel::GLFramebufferTexture::CreateGLFramebufferTexture(unsigned int, int, int)
// RVA: 0x13f5ac, Size: 288 bytes
int64_t _ZN14MTFilterKernel20GLFramebufferTexture26CreateGLFramebufferTextureEjii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x13f5e4
    glBindFramebuffer(...); // call PLT API at 0x13f5f0
    glFramebufferTexture2D(...); // call PLT API at 0x13f608
    glCheckFramebufferStatus(...); // call PLT API at 0x13f610
    _Znwm(...); // call PLT API at 0x13f628
    _ZN14MTFilterKernel20GLFramebufferTextureC2Ejjii(...); // call internal at 0x13f640
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x13f650
    const char* str = "FilterKernel";
    const char* str = "ERROR: glCheckFramebufferStatus status = %d";
    __android_log_print(...); // call PLT API at 0x13f674
    return a0;
    _ZdlPv(...); // call PLT API at 0x13f6ac
    sub_1B0544(...); // call internal at 0x13f6c4
    __stack_chk_fail(...); // call PLT API at 0x13f6c8
}
