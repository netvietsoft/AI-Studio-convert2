// Function: MTFilterKernel::CMTPaintFilter::PurpleToYellowToFBO(int, int, int)
// RVA: 0x128000, Size: 444 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter19PurpleToYellowToFBOEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x128048
    glViewport(...); // call PLT API at 0x128060
    glClearColor(...); // call PLT API at 0x128074
    glClear(...); // call PLT API at 0x12807c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x128084
    glActiveTexture(...); // call PLT API at 0x12808c
    glBindTexture(...); // call PLT API at 0x128098
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1280ac
    const char* str = "imgSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x1280c4
    const char* str = "tensorRadius";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1280d8
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128118
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x128144
    glDrawArrays(...); // call PLT API at 0x128154
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x128160
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12816c
    glBindFramebuffer(...); // call PLT API at 0x128178
    glUseProgram(...); // call PLT API at 0x128180
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1281b8
}
