// Function: MTFilterKernel::GPUImageFramebuffer::generateTexture()
// RVA: 0x1642d8, Size: 124 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer15generateTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call PLT API at 0x1642f4
    glBindTexture(...); // call PLT API at 0x164300
    glTexParameteri(...); // call PLT API at 0x164310
    glTexParameteri(...); // call PLT API at 0x164320
    glTexParameteri(...); // call PLT API at 0x164330
    glTexParameteri(...); // call PLT API at 0x164340
    return a0;
}
