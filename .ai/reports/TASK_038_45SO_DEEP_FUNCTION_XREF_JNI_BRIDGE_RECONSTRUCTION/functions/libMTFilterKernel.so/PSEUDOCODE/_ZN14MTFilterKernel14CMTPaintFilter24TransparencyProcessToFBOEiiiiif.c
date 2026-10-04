// Function: MTFilterKernel::CMTPaintFilter::TransparencyProcessToFBO(int, int, int, int, int, float)
// RVA: 0x1281bc, Size: 568 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter24TransparencyProcessToFBOEiiiiif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x128218
    glViewport(...); // call PLT API at 0x128230
    glClearColor(...); // call PLT API at 0x128244
    glClear(...); // call PLT API at 0x12824c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x128254
    glActiveTexture(...); // call PLT API at 0x12825c
    glBindTexture(...); // call PLT API at 0x128268
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12827c
    glActiveTexture(...); // call PLT API at 0x128284
    glBindTexture(...); // call PLT API at 0x128290
    const char* str = "tensorFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1282a4
    const char* str = "imgSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x1282bc
    const char* str = "sigma";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1282d8
    const char* str = "sigma2";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1282f4
    const char* str = "Radians";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128308
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128348
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128374
    glDrawArrays(...); // call PLT API at 0x128384
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x128390
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12839c
    glBindFramebuffer(...); // call PLT API at 0x1283a8
    glUseProgram(...); // call PLT API at 0x1283b0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1283f0
}
