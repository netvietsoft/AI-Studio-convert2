// Function: MTFilterKernel::CMTPaintFilter::LittleProcessToFBO(int, int, int, int&, int&)
// RVA: 0x127918, Size: 432 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter18LittleProcessToFBOEiiiRiS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x127980
    glViewport(...); // call PLT API at 0x127998
    glClearColor(...); // call PLT API at 0x1279ac
    glClear(...); // call PLT API at 0x1279b4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1279bc
    glActiveTexture(...); // call PLT API at 0x1279c4
    glBindTexture(...); // call PLT API at 0x1279d0
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1279e4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127a24
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127a50
    glDrawArrays(...); // call PLT API at 0x127a60
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127a6c
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127a78
    glBindFramebuffer(...); // call PLT API at 0x127a84
    glUseProgram(...); // call PLT API at 0x127a8c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x127ac4
}
