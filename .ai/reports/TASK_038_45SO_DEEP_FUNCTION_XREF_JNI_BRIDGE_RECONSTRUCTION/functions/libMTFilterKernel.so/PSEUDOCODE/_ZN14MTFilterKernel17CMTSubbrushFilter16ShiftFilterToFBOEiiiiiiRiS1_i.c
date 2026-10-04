// Function: MTFilterKernel::CMTSubbrushFilter::ShiftFilterToFBO(int, int, int, int, int, int, int&, int&, int)
// RVA: 0x12c1d4, Size: 720 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter16ShiftFilterToFBOEiiiiiiRiS1_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12c238
    glViewport(...); // call PLT API at 0x12c254
    glClearColor(...); // call PLT API at 0x12c268
    glClear(...); // call PLT API at 0x12c270
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12c278
    const char* str = "projection";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12c2ac
    const char* str = "modelview";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12c2f8
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix3fvEPKcPKfbi(...); // call internal at 0x12c330
    const char* str = "shiftValues";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12c344
    glActiveTexture(...); // call PLT API at 0x12c34c
    glBindTexture(...); // call PLT API at 0x12c358
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c36c
    glActiveTexture(...); // call PLT API at 0x12c374
    glBindTexture(...); // call PLT API at 0x12c380
    const char* str = "meanGuideTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c394
    glActiveTexture(...); // call PLT API at 0x12c39c
    glBindTexture(...); // call PLT API at 0x12c3a8
    const char* str = "scaleTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12c3bc
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12c414
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12c43c
    glDrawArrays(...); // call PLT API at 0x12c44c
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12c458
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12c464
    glBindFramebuffer(...); // call PLT API at 0x12c470
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12c4a0
}
