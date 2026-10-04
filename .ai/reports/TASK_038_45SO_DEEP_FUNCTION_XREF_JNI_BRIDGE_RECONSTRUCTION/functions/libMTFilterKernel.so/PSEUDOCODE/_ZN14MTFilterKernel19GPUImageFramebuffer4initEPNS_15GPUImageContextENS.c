// Function: MTFilterKernel::GPUImageFramebuffer::init(MTFilterKernel::GPUImageContext*, MTFilterKernel::CGSize, MTFilterKernel::GPUTextureOptions, bool, unsigned int, unsigned int, int)
// RVA: 0x164068, Size: 356 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer4initEPNS_15GPUImageContextENS_6CGSizeENS_17GPUTextureOptionsEbjji(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    glGenTextures(...); // call PLT API at 0x1640f0
    glBindTexture(...); // call PLT API at 0x1640fc
    glTexParameteri(...); // call PLT API at 0x16410c
    glTexParameteri(...); // call PLT API at 0x16411c
    glTexParameteri(...); // call PLT API at 0x16412c
    glTexParameteri(...); // call PLT API at 0x16413c
    return a0;
    _ZN14MTFilterKernel19GPUImageFramebuffer19generateFramebufferEv(...); // call internal at 0x164160
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x164168
    const char* str = "FilterKernel";
    const char* str = "ERROR: textureID = %d, framebufferID = %d";
    __android_log_print(...); // call PLT API at 0x164194
    return a0;
    return a0;
}
