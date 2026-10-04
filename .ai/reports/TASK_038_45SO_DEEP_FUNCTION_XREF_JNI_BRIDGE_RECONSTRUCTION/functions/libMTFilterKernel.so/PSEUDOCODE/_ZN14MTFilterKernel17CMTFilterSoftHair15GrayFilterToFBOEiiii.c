// Function: MTFilterKernel::CMTFilterSoftHair::GrayFilterToFBO(int, int, int, int)
// RVA: 0x13488c, Size: 228 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair15GrayFilterToFBOEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x1348b4
    glViewport(...); // call PLT API at 0x1348c8
    glClear(...); // call PLT API at 0x1348d0
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1348d8
    glActiveTexture(...); // call PLT API at 0x1348e0
    glBindTexture(...); // call PLT API at 0x1348ec
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134900
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134928
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134950
    glDrawArrays(...); // call PLT API at 0x13496c
}
