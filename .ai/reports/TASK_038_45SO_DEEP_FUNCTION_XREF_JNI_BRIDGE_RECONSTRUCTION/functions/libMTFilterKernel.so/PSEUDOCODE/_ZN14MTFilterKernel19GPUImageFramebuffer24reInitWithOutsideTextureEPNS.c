// Function: MTFilterKernel::GPUImageFramebuffer::reInitWithOutsideTexture(MTFilterKernel::GPUImageContext*, MTFilterKernel::CGSize, MTFilterKernel::GPUTextureOptions, bool, unsigned int, unsigned int, int)
// RVA: 0x1641cc, Size: 268 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer24reInitWithOutsideTextureEPNS_15GPUImageContextENS_6CGSizeENS_17GPUTextureOptionsEbjji(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x16423c
    glDeleteTextures(...); // call PLT API at 0x164260
    _ZN14MTFilterKernel19GPUImageFramebuffer4initEPNS_15GPUImageContextENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0x16429c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1642d4
}
