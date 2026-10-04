// Function: MTFilterKernel::CMTPaintFilter::Rgb2BwaToFBO(int, int, int)
// RVA: 0x127cb4, Size: 400 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter12Rgb2BwaToFBOEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x127cfc
    glViewport(...); // call PLT API at 0x127d14
    glClearColor(...); // call PLT API at 0x127d28
    glClear(...); // call PLT API at 0x127d30
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x127d38
    glActiveTexture(...); // call PLT API at 0x127d40
    glBindTexture(...); // call PLT API at 0x127d4c
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x127d60
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127da0
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127dcc
    glDrawArrays(...); // call PLT API at 0x127ddc
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127de8
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127df4
    glBindFramebuffer(...); // call PLT API at 0x127e00
    glUseProgram(...); // call PLT API at 0x127e08
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x127e40
}
