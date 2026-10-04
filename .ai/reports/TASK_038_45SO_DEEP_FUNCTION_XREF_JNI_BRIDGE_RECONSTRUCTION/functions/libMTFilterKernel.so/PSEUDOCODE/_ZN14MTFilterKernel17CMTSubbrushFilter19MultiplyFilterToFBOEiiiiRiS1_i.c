// Function: MTFilterKernel::CMTSubbrushFilter::MultiplyFilterToFBO(int, int, int, int, int&, int&, int)
// RVA: 0x12b87c, Size: 604 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter19MultiplyFilterToFBOEiiiiRiS1_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12b8d4
    glViewport(...); // call PLT API at 0x12b8f0
    glClearColor(...); // call PLT API at 0x12b904
    glClear(...); // call PLT API at 0x12b90c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12b914
    const char* str = "projection";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12b948
    const char* str = "modelview";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12b994
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix3fvEPKcPKfbi(...); // call internal at 0x12b9cc
    glActiveTexture(...); // call PLT API at 0x12b9d4
    glBindTexture(...); // call PLT API at 0x12b9e0
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12b9f4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12ba4c
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12ba74
    glDrawArrays(...); // call PLT API at 0x12ba84
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12ba90
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12ba9c
    glBindFramebuffer(...); // call PLT API at 0x12baa8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12bad4
}
