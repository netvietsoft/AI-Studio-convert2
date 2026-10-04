// Function: MTFilterKernel::CMTFilterSoftHair::BlurVFilterToFBO(int, int, int, int)
// RVA: 0x134c10, Size: 384 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair16BlurVFilterToFBOEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x134c4c
    glViewport(...); // call PLT API at 0x134c60
    glClear(...); // call PLT API at 0x134c68
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x134ca8
    const char* str = "Weights";
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(...); // call internal at 0x134cc0
    const char* str = "Offsets";
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(...); // call internal at 0x134cd8
    glActiveTexture(...); // call PLT API at 0x134ce0
    glBindTexture(...); // call PLT API at 0x134cec
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134d00
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134d28
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134d50
    glDrawArrays(...); // call PLT API at 0x134d60
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x134d8c
}
