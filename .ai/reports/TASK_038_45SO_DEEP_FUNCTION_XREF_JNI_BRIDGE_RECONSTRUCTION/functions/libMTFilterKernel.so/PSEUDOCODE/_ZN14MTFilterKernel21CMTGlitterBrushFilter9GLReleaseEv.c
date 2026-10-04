// Function: MTFilterKernel::CMTGlitterBrushFilter::GLRelease()
// RVA: 0x12573c, Size: 164 bytes
int64_t _ZN14MTFilterKernel21CMTGlitterBrushFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(...); // call internal at 0x12574c
    glDeleteFramebuffers(...); // call PLT API at 0x125764
    glDeleteTextures(...); // call PLT API at 0x125780
    glDeleteTextures(...); // call PLT API at 0x12579c
    glDeleteTextures(...); // call PLT API at 0x1257b8
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x1257d0
    return a0;
}
