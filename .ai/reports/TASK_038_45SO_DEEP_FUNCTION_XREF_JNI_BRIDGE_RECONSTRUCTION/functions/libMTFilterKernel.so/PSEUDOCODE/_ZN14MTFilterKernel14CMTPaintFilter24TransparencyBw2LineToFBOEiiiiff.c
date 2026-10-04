// Function: MTFilterKernel::CMTPaintFilter::TransparencyBw2LineToFBO(int, int, int, int, float, float)
// RVA: 0x128610, Size: 532 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter24TransparencyBw2LineToFBOEiiiiff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12866c
    glViewport(...); // call PLT API at 0x128684
    glClearColor(...); // call PLT API at 0x128698
    glClear(...); // call PLT API at 0x1286a0
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1286a8
    glActiveTexture(...); // call PLT API at 0x1286b0
    glBindTexture(...); // call PLT API at 0x1286bc
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1286d0
    glActiveTexture(...); // call PLT API at 0x1286d8
    glBindTexture(...); // call PLT API at 0x1286e4
    const char* str = "tensorFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1286f8
    const char* str = "imgSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x128710
    const char* str = "threshold";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128724
    const char* str = "Level";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128738
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128778
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x1287a4
    glDrawArrays(...); // call PLT API at 0x1287b4
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1287c0
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1287cc
    glBindFramebuffer(...); // call PLT API at 0x1287d8
    glUseProgram(...); // call PLT API at 0x1287e0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x128820
}
