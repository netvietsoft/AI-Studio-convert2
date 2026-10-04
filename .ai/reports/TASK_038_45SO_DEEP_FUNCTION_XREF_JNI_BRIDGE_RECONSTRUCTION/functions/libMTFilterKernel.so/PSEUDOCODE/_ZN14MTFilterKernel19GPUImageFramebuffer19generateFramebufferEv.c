// Function: MTFilterKernel::GPUImageFramebuffer::generateFramebuffer()
// RVA: 0x164354, Size: 412 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer19generateFramebufferEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenFramebuffers(...); // call PLT API at 0x16437c
    glBindFramebuffer(...); // call PLT API at 0x164388
    glGenTextures(...); // call PLT API at 0x164398
    glBindTexture(...); // call PLT API at 0x1643a4
    glTexParameteri(...); // call PLT API at 0x1643b4
    glTexParameteri(...); // call PLT API at 0x1643c4
    glTexParameteri(...); // call PLT API at 0x1643d4
    glTexParameteri(...); // call PLT API at 0x1643e4
    glBindTexture(...); // call PLT API at 0x1643f4
    glTexImage2D(...); // call PLT API at 0x16441c
    glFramebufferTexture2D(...); // call PLT API at 0x164434
    glCheckFramebufferStatus(...); // call PLT API at 0x16443c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x164450
    glGetError(...); // call PLT API at 0x164468
    glIsTexture(...); // call PLT API at 0x164478
    glIsFramebuffer(...); // call PLT API at 0x164488
    const char* str = "FilterKernel";
    const char* str = "ERROR: Incomplete filter FBO: %d; framebuffer size = %d, %d, glerror = %d, isTexture = %d, isFramebuffer = %d.";
    __android_log_print(...); // call PLT API at 0x1644bc
    return a0;
    return a0;
}
