// Function: MTFilterKernel::GPUImageFramebuffer::~GPUImageFramebuffer()
// RVA: 0x163f08, Size: 116 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebufferD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x163f44
    glDeleteTextures(...); // call PLT API at 0x163f64
    return a0;
    sub_C0B38(...); // call internal at 0x163f78
}
