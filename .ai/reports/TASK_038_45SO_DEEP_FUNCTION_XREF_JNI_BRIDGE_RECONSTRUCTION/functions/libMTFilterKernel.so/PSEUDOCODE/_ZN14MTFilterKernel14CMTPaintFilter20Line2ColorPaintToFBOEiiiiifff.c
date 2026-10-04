// Function: MTFilterKernel::CMTPaintFilter::Line2ColorPaintToFBO(int, int, int, int, int, float, float, float)
// RVA: 0x1283f4, Size: 540 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter20Line2ColorPaintToFBOEiiiiifff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x128458
    glViewport(...); // call PLT API at 0x128470
    glClearColor(...); // call PLT API at 0x128484
    glClear(...); // call PLT API at 0x12848c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x128494
    glActiveTexture(...); // call PLT API at 0x12849c
    glBindTexture(...); // call PLT API at 0x1284a8
    const char* str = "edgeFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1284bc
    glActiveTexture(...); // call PLT API at 0x1284c4
    glBindTexture(...); // call PLT API at 0x1284d0
    const char* str = "bilFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1284e4
    const char* str = "Saturation";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1284f8
    const char* str = "gamma";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12850c
    const char* str = "Level";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128520
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128560
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12858c
    glDrawArrays(...); // call PLT API at 0x12859c
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1285a8
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1285b4
    glBindFramebuffer(...); // call PLT API at 0x1285c0
    glUseProgram(...); // call PLT API at 0x1285c8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12860c
}
