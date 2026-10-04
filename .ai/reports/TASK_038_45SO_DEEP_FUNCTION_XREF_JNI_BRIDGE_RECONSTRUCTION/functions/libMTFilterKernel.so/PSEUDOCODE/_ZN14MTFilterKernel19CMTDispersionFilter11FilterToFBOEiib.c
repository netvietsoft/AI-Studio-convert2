// Function: MTFilterKernel::CMTDispersionFilter::FilterToFBO(int, int, bool)
// RVA: 0x125240, Size: 476 bytes
int64_t _ZN14MTFilterKernel19CMTDispersionFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x1252a4
    glViewport(...); // call PLT API at 0x1252d8
    glClear(...); // call PLT API at 0x1252e0
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x1252e8
    glActiveTexture(...); // call PLT API at 0x1252f0
    glBindTexture(...); // call PLT API at 0x125300
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x125314
    const char* str = "prismR";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x125328
    const char* str = "refraction";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x125344
    const char* str = "coordinate";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x125358
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12537c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x1253a0
    glDrawArrays(...); // call PLT API at 0x1253b0
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x1253bc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1253cc
    const char* str = "FilterKernel";
    const char* str = "bind fbo fail";
    __android_log_print(...); // call PLT API at 0x1253ec
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x125418
}
