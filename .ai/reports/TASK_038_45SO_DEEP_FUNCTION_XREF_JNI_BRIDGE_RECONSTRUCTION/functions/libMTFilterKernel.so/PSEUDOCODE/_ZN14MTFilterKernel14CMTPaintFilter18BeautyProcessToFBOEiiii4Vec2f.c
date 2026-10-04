// Function: MTFilterKernel::CMTPaintFilter::BeautyProcessToFBO(int, int, int, int, Vec2, float)
// RVA: 0x127ac8, Size: 492 bytes
int64_t _ZN14MTFilterKernel14CMTPaintFilter18BeautyProcessToFBOEiiii4Vec2f(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x127b24
    glViewport(...); // call PLT API at 0x127b3c
    glClearColor(...); // call PLT API at 0x127b50
    glClear(...); // call PLT API at 0x127b58
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x127b60
    glActiveTexture(...); // call PLT API at 0x127b68
    glBindTexture(...); // call PLT API at 0x127b74
    const char* str = "videoFrame";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x127b88
    const char* str = "ImageSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x127ba0
    const char* str = "Offset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x127bb4
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x127bc8
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127c08
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x127c34
    glDrawArrays(...); // call PLT API at 0x127c44
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127c50
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x127c5c
    glBindFramebuffer(...); // call PLT API at 0x127c68
    glUseProgram(...); // call PLT API at 0x127c70
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x127cb0
}
