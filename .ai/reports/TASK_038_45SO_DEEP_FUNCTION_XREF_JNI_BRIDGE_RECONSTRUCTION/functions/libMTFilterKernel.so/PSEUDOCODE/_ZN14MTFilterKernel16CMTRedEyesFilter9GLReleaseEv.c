// Function: MTFilterKernel::CMTRedEyesFilter::GLRelease()
// RVA: 0x1299c4, Size: 124 bytes
int64_t _ZN14MTFilterKernel16CMTRedEyesFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(...); // call internal at 0x1299d4
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x1299e0
    glDeleteFramebuffers(...); // call PLT API at 0x1299f8
    glDeleteTextures(...); // call PLT API at 0x129a14
    glDeleteTextures(...); // call PLT API at 0x129a2c
    return a0;
}
