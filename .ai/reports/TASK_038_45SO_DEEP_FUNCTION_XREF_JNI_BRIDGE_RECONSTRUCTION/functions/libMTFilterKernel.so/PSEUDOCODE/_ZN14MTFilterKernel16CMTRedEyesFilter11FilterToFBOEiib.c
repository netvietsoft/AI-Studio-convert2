// Function: MTFilterKernel::CMTRedEyesFilter::FilterToFBO(int, int, bool)
// RVA: 0x129b60, Size: 668 bytes
int64_t _ZN14MTFilterKernel16CMTRedEyesFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x129ba4
    glViewport(...); // call PLT API at 0x129bc0
    glClearColor(...); // call PLT API at 0x129bd4
    glClear(...); // call PLT API at 0x129bdc
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x129be4
    const char* str = "alpha";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x129bf8
    glActiveTexture(...); // call PLT API at 0x129c00
    glBindTexture(...); // call PLT API at 0x129c0c
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x129c20
    glActiveTexture(...); // call PLT API at 0x129c28
    glBindTexture(...); // call PLT API at 0x129c34
    const char* str = "topSucaiTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x129c48
    sub_1AFCA4(...); // call internal at 0x129c70
    const char* str = "mvpMatrix";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x129ccc
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x129d28
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x129d4c
    glDrawArrays(...); // call PLT API at 0x129d5c
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x129d68
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x129d78
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x129d88
    glBindFramebuffer(...); // call PLT API at 0x129d94
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x129da0
    const char* str = "FilterKernel";
    const char* str = "BindFBO fail-->CMTRedEyesFilter::FilterToFBO";
    __android_log_print(...); // call PLT API at 0x129dc0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x129df8
}
