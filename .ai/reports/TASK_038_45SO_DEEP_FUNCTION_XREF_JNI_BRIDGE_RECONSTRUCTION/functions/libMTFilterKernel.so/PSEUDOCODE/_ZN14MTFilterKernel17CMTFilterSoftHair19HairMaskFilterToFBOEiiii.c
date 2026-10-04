// Function: MTFilterKernel::CMTFilterSoftHair::HairMaskFilterToFBO(int, int, int, int)
// RVA: 0x134970, Size: 288 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair19HairMaskFilterToFBOEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x1349a0
    glViewport(...); // call PLT API at 0x1349b4
    glClear(...); // call PLT API at 0x1349bc
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1349c4
    const char* str = "shiftingSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x1349f4
    glActiveTexture(...); // call PLT API at 0x1349fc
    glBindTexture(...); // call PLT API at 0x134a08
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134a1c
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134a44
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134a6c
    glDrawArrays(...); // call PLT API at 0x134a8c
}
