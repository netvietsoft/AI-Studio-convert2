// Function: MTFilterKernel::CMTToneCurveFilter::FilterToFBO(int, int, bool)
// RVA: 0x12df4c, Size: 1100 bytes
int64_t _ZN14MTFilterKernel18CMTToneCurveFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x12dfc0
    glDeleteTextures(...); // call PLT API at 0x12dfdc
    glDeleteTextures(...); // call PLT API at 0x12dff8
    _ZdlPv(...); // call PLT API at 0x12e060
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm(...); // call internal at 0x12e0a8
    memcpy(...); // call PLT API at 0x12e0bc
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x12e138
    sub_1AFCA4(...); // call internal at 0x12e164
    glViewport(...); // call PLT API at 0x12e1a8
    glClearColor(...); // call PLT API at 0x12e1bc
    glClear(...); // call PLT API at 0x12e1c4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12e1cc
    const char* str = "mvpMatrix";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12e228
    const char* str = "alpha";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x12e23c
    glActiveTexture(...); // call PLT API at 0x12e244
    glBindTexture(...); // call PLT API at 0x12e250
    const char* str = "inputImageTexture0";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12e264
    glActiveTexture(...); // call PLT API at 0x12e26c
    glBindTexture(...); // call PLT API at 0x12e278
    const char* str = "inputImageTexture1";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12e28c
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12e2b0
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12e2d4
    glDrawArrays(...); // call PLT API at 0x12e2e4
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x12e2f4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12e304
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12e314
    glUseProgram(...); // call PLT API at 0x12e31c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x12e334
    const char* str = "FilterKernel";
    const char* str = "BindFBO fail-->CMTGlitterBrushFilter::FilterToFBO";
    __android_log_print(...); // call PLT API at 0x12e354
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12e394
}
