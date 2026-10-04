// Function: MTFilterKernel::CMTFilterSoftHair::ReleaseFramebufferTexture()
// RVA: 0x1341bc, Size: 252 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair25ReleaseFramebufferTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x1341e0
    glDeleteTextures(...); // call PLT API at 0x1341fc
    glDeleteFramebuffers(...); // call PLT API at 0x134218
    glDeleteTextures(...); // call PLT API at 0x134234
    glDeleteFramebuffers(...); // call PLT API at 0x134250
    glDeleteTextures(...); // call PLT API at 0x13426c
    glDeleteFramebuffers(...); // call PLT API at 0x134288
    glDeleteTextures(...); // call PLT API at 0x1342a4
    return a0;
}
