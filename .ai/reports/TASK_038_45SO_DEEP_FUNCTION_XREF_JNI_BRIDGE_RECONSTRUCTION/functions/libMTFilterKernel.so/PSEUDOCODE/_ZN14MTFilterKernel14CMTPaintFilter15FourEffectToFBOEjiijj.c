// Function: MTFilterKernel::CMTPaintFilter::FourEffectToFBO(unsigned int, int, int, unsigned int, unsigned int)
// RVA: 0x128a30, Size: 576 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter15FourEffectToFBOEjiijj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x128a84
    glViewport(...); // call PLT API at 0x128a9c
    glClearColor(...); // call PLT API at 0x128ab0
    glClear(...); // call PLT API at 0x128ab8
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x128ac0
    glActiveTexture(...); // call PLT API at 0x128ac8
    glBindTexture(...); // call PLT API at 0x128ad4
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x128ae8
    glActiveTexture(...); // call PLT API at 0x128af0
    glBindTexture(...); // call PLT API at 0x128afc
    const char* str = "ColorBalance0";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x128b10
    glActiveTexture(...); // call PLT API at 0x128b18
    glBindTexture(...); // call PLT API at 0x128b24
    const char* str = "Curve0";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x128b38
    const char* str = "clColor";
    _ZN14MTFilterKernel10CGLProgram12SetUniform3fEPKcfff(...); // call internal at 0x128b6c
    const char* str = "Level";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128b88
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128bc8
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128bf4
    glDrawArrays(...); // call PLT API at 0x128c04
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x128c10
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x128c1c
    glBindFramebuffer(...); // call PLT API at 0x128c28
    glUseProgram(...); // call PLT API at 0x128c30
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x128c6c
}
