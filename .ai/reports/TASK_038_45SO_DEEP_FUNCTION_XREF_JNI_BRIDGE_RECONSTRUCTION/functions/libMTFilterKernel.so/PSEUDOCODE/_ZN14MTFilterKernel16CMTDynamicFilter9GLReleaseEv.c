// Function: MTFilterKernel::CMTDynamicFilter::GLRelease()
// RVA: 0x11c71c, Size: 116 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x11c740
    glDeleteTextures(...); // call PLT API at 0x11c75c
    glDeleteProgram(...); // call PLT API at 0x11c76c
    glDeleteProgram(...); // call PLT API at 0x11c77c
    return a0;
}
