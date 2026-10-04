// Function: MTFilterKernel::CMTGaussianFilter::~CMTGaussianFilter()
// RVA: 0x120be0, Size: 124 bytes
int64_t _ZN14MTFilterKernel17CMTGaussianFilterD2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call PLT API at 0x120c14
    glDeleteFramebuffers(...); // call PLT API at 0x120c30
    glDeleteProgram(...); // call PLT API at 0x120c40
    _ZN14MTFilterKernel16CMTDynamicFilterD1Ev(...); // call internal at 0x120c54
    sub_C0B38(...); // call internal at 0x120c58
}
