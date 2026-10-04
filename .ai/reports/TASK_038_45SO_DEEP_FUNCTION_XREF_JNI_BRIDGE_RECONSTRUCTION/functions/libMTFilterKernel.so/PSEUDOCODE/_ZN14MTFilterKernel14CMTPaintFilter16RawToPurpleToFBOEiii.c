// Function: MTFilterKernel::CMTPaintFilter::RawToPurpleToFBO(int, int, int)
// RVA: 0x127e44, Size: 444 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter16RawToPurpleToFBOEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x127e8c
    glViewport(...); // call PLT API at 0x127ea4
    glClearColor(...); // call PLT API at 0x127eb8
    glClear(...); // call PLT API at 0x127ec0
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x127ec8
    glActiveTexture(...); // call PLT API at 0x127ed0
    glBindTexture(...); // call PLT API at 0x127edc
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x127ef0
    const char* str = "imgSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x127f08
    const char* str = "threshold";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x127f1c
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127f5c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127f88
    glDrawArrays(...); // call PLT API at 0x127f98
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127fa4
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127fb0
    glBindFramebuffer(...); // call PLT API at 0x127fbc
    glUseProgram(...); // call PLT API at 0x127fc4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x127ffc
}
