// Function: MTFilterKernel::CMTFilterSoftHair::BlurHFilterToFBO(int, int, int, int)
// RVA: 0x134a90, Size: 384 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair16BlurHFilterToFBOEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x134acc
    glViewport(...); // call PLT API at 0x134ae0
    glClear(...); // call PLT API at 0x134ae8
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x134b28
    const char* str = "Weights";
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(...); // call internal at 0x134b40
    const char* str = "Offsets";
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(...); // call internal at 0x134b58
    glActiveTexture(...); // call PLT API at 0x134b60
    glBindTexture(...); // call PLT API at 0x134b6c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134b80
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134ba8
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134bd0
    glDrawArrays(...); // call PLT API at 0x134be0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x134c0c
}
