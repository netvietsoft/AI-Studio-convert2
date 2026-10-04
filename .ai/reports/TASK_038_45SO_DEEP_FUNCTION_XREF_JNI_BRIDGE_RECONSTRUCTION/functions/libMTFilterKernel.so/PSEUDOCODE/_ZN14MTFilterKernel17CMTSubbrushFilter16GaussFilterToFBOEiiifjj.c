// Function: MTFilterKernel::CMTSubbrushFilter::GaussFilterToFBO(int, int, int, float, unsigned int, unsigned int)
// RVA: 0x12bbb8, Size: 796 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter16GaussFilterToFBOEiiifjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12bc14
    glViewport(...); // call PLT API at 0x12bc2c
    glClearColor(...); // call PLT API at 0x12bc40
    glClear(...); // call PLT API at 0x12bc48
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12bc70
    glActiveTexture(...); // call PLT API at 0x12bc78
    glBindTexture(...); // call PLT API at 0x12bc84
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12bc98
    const char* str = "texelWidthOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12bcac
    const char* str = "texelHeightOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12bcc4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12bcec
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12bd14
    glDrawArrays(...); // call PLT API at 0x12bd24
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12bd30
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12bd3c
    glBindFramebuffer(...); // call PLT API at 0x12bd48
    glUseProgram(...); // call PLT API at 0x12bd50
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12bd68
    glClearColor(...); // call PLT API at 0x12bd80
    glClear(...); // call PLT API at 0x12bd88
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12bd90
    glActiveTexture(...); // call PLT API at 0x12bd98
    glBindTexture(...); // call PLT API at 0x12bda4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12bdb8
    const char* str = "texelWidthOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12bdd0
    const char* str = "texelHeightOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12bde4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12be0c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12be34
    glDrawArrays(...); // call PLT API at 0x12be44
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12be50
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12be5c
    glBindFramebuffer(...); // call PLT API at 0x12be68
    glUseProgram(...); // call PLT API at 0x12be70
    glDeleteFramebuffers(...); // call PLT API at 0x12be84
    glDeleteTextures(...); // call PLT API at 0x12be9c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12bed0
}
