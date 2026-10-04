// Function: MTFilterKernel::GPUImageFramebuffer::destroyFramebuffer()
// RVA: 0x163f7c, Size: 96 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer18destroyFramebufferEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x163fa8
    glDeleteTextures(...); // call PLT API at 0x163fc8
    return a0;
}
