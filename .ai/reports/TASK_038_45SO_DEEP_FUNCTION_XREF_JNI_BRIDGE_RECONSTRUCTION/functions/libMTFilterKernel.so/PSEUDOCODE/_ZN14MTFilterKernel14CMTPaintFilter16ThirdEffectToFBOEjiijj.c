// Function: MTFilterKernel::CMTPaintFilter::ThirdEffectToFBO(unsigned int, int, int, unsigned int, unsigned int)
// RVA: 0x128824, Size: 524 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter16ThirdEffectToFBOEjiijj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x128878
    glViewport(...); // call PLT API at 0x128890
    glClearColor(...); // call PLT API at 0x1288a4
    glClear(...); // call PLT API at 0x1288ac
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1288b4
    glActiveTexture(...); // call PLT API at 0x1288bc
    glBindTexture(...); // call PLT API at 0x1288c8
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1288dc
    glActiveTexture(...); // call PLT API at 0x1288e4
    glBindTexture(...); // call PLT API at 0x1288f0
    const char* str = "cloudFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x128904
    glActiveTexture(...); // call PLT API at 0x12890c
    glBindTexture(...); // call PLT API at 0x128918
    const char* str = "gradientFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12892c
    const char* str = "Level";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x128948
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128988
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x1289b4
    glDrawArrays(...); // call PLT API at 0x1289c4
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1289d0
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1289dc
    glBindFramebuffer(...); // call PLT API at 0x1289e8
    glUseProgram(...); // call PLT API at 0x1289f0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x128a2c
}
