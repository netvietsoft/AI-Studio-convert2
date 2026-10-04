// Function: MTFilterKernel::CMTRandomNoiseFilter::FilterToFBO(int, int, bool)
// RVA: 0x129328, Size: 724 bytes
int64_t _ZN14MTFilterKernel20CMTRandomNoiseFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x129388
    glDeleteTextures(...); // call PLT API at 0x1293a4
    (*x8)(...);
    (*x8)(...);
    glViewport(...); // call PLT API at 0x1293dc
    glClear(...); // call PLT API at 0x129404
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12940c
    glActiveTexture(...); // call PLT API at 0x129414
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x129438
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12945c
    glDrawArrays(...); // call PLT API at 0x12946c
    _ZN14MTFilterKernel16CMTDynamicFilter9UnBindFBOEv(...); // call internal at 0x129474
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x129480
    glViewport(...); // call PLT API at 0x129494
    glClear(...); // call PLT API at 0x12949c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1294a4
    glActiveTexture(...); // call PLT API at 0x1294ac
    glBindTexture(...); // call PLT API at 0x1294bc
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1294d0
    glActiveTexture(...); // call PLT API at 0x1294d8
    glBindTexture(...); // call PLT API at 0x1294e4
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1294f8
    const char* str = "degree";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12950c
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x129530
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x129554
    glDrawArrays(...); // call PLT API at 0x129564
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x129570
    __stack_chk_fail(...); // call PLT API at 0x12958c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x129590
    const char* str = "FilterKernel";
    const char* str = "bind temp fbo failed";
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1295b0
    const char* str = "FilterKernel";
    const char* str = "bind fbo fail";
    __android_log_print(...); // call PLT API at 0x1295d0
    return a0;
}
