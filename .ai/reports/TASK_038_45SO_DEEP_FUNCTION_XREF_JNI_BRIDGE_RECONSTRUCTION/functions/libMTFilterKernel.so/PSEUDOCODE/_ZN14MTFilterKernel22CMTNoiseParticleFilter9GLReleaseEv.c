// Function: MTFilterKernel::CMTNoiseParticleFilter::GLRelease()
// RVA: 0x126414, Size: 124 bytes
int64_t _ZN14MTFilterKernel22CMTNoiseParticleFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(...); // call internal at 0x126424
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x126430
    glDeleteFramebuffers(...); // call PLT API at 0x126448
    glDeleteTextures(...); // call PLT API at 0x126464
    glDeleteTextures(...); // call PLT API at 0x12647c
    return a0;
}
