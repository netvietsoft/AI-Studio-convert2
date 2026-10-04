// Function: MTFilterKernel::CMTSubbrushFilter::ScaleFilterToFBO(int, int, int, int, int, int, int&, int&, int)
// RVA: 0x12bed4, Size: 768 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter16ScaleFilterToFBOEiiiiiiRiS1_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12bf38
    glViewport(...); // call PLT API at 0x12bf54
    glClearColor(...); // call PLT API at 0x12bf68
    glClear(...); // call PLT API at 0x12bf70
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12bf78
    const char* str = "projection";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12bfac
    const char* str = "modelview";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12bff8
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix3fvEPKcPKfbi(...); // call internal at 0x12c030
    const char* str = "smoothingDegree";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12c04c
    glActiveTexture(...); // call PLT API at 0x12c054
    glBindTexture(...); // call PLT API at 0x12c060
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c074
    glActiveTexture(...); // call PLT API at 0x12c07c
    glBindTexture(...); // call PLT API at 0x12c088
    const char* str = "meanSquareGuideTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c09c
    glActiveTexture(...); // call PLT API at 0x12c0a4
    glBindTexture(...); // call PLT API at 0x12c0b0
    const char* str = "meanInputMultipliedByGuideTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c0c4
    glActiveTexture(...); // call PLT API at 0x12c0cc
    glBindTexture(...); // call PLT API at 0x12c0d8
    const char* str = "meanGuideTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c0ec
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12c144
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12c16c
    glDrawArrays(...); // call PLT API at 0x12c17c
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12c188
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12c194
    glBindFramebuffer(...); // call PLT API at 0x12c1a0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12c1d0
}
