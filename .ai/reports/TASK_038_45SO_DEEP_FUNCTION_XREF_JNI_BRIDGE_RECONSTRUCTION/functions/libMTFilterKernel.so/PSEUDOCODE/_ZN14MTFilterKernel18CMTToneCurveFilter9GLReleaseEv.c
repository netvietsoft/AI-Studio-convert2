// Function: MTFilterKernel::CMTToneCurveFilter::GLRelease()
// RVA: 0x12caf8, Size: 72 bytes
int64_t _ZN14MTFilterKernel18CMTToneCurveFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(...); // call internal at 0x12cb08
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12cb14
    glDeleteTextures(...); // call PLT API at 0x12cb2c
    return a0;
}
