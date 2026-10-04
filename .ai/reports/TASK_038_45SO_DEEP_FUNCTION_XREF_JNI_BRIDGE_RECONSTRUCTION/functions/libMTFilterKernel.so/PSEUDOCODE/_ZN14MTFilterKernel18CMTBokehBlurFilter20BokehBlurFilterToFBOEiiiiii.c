// Function: MTFilterKernel::CMTBokehBlurFilter::BokehBlurFilterToFBO(int, int, int, int, int, int)
// RVA: 0x1230d4, Size: 612 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter20BokehBlurFilterToFBOEiiiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x123120
    glViewport(...); // call PLT API at 0x123134
    glClear(...); // call PLT API at 0x12313c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x123144
    const char* str = "imageheight";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123158
    const char* str = "imagewidth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12316c
    const char* str = "maskradius";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123180
    const char* str = "farDepth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12319c
    const char* str = "nearDepth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1231b0
    const char* str = "farRadius";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1231c4
    const char* str = "nearRadius";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1231d8
    const char* str = "highlights";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1231ec
    const char* str = "vivid";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123200
    const char* str = "mattebox";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123214
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123248
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12327c
    glActiveTexture(...); // call PLT API at 0x123284
    glBindTexture(...); // call PLT API at 0x123290
    const char* str = "inputImage";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1232a4
    glActiveTexture(...); // call PLT API at 0x1232ac
    glBindTexture(...); // call PLT API at 0x1232b8
    const char* str = "diaphragmImage";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1232cc
    glActiveTexture(...); // call PLT API at 0x1232d4
    glBindTexture(...); // call PLT API at 0x1232e0
    const char* str = "maskResult";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1232f4
    glDrawArrays(...); // call PLT API at 0x123304
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x123334
}
