// Function: MTFilterKernel::CMTSubbrushFilter::GLRelease()
// RVA: 0x12a040, Size: 232 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter9GLReleaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter9GLReleaseEv(...); // call internal at 0x12a050
    _ZN14MTFilterKernel17CMTSubbrushFilter25ReleaseFramebufferTextureEv(...); // call internal at 0x12a058
    glDeleteTextures(...); // call PLT API at 0x12a070
    glDeleteTextures(...); // call PLT API at 0x12a08c
    glDeleteTextures(...); // call PLT API at 0x12a0a8
    glDeleteTextures(...); // call PLT API at 0x12a0c4
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a0d4
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a0e0
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a0ec
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a0f8
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a104
    _ZN14MTFilterKernel10CGLProgram9GLReleaseEv(...); // call internal at 0x12a118
    return a0;
}
