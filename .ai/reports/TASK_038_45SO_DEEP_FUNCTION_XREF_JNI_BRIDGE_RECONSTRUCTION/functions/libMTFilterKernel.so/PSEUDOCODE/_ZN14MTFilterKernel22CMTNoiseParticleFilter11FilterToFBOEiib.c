// Function: MTFilterKernel::CMTNoiseParticleFilter::FilterToFBO(int, int, bool)
// RVA: 0x1268ec, Size: 1500 bytes
int64_t _ZN14MTFilterKernel22CMTNoiseParticleFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram12GetProgramIDEv(...); // call internal at 0x12693c
    glDeleteFramebuffers(...); // call PLT API at 0x126978
    glDeleteTextures(...); // call PLT API at 0x126994
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm(...); // call internal at 0x126a48
    memcpy(...); // call PLT API at 0x126a5c
    _ZdlPv(...); // call PLT API at 0x126aa4
    _Znam(...); // call PLT API at 0x126af0
    memcpy(...); // call PLT API at 0x126b00
    rand(...); // call PLT API at 0x126b48
    glBindTexture(...); // call PLT API at 0x126b98
    glTexSubImage2D(...); // call PLT API at 0x126bc0
    glBindTexture(...); // call PLT API at 0x126bcc
    _ZdaPv(...); // call PLT API at 0x126bd4
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x126be4
    glViewport(...); // call PLT API at 0x126c00
    glClearColor(...); // call PLT API at 0x126c14
    glClear(...); // call PLT API at 0x126c1c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x126c24
    glActiveTexture(...); // call PLT API at 0x126c2c
    glBindTexture(...); // call PLT API at 0x126c38
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x126c4c
    glActiveTexture(...); // call PLT API at 0x126c54
    glBindTexture(...); // call PLT API at 0x126c60
    const char* str = "mt_tempData1";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x126c74
    const char* str = "pixelSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x126ca0
    const char* str = "sourceSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x126cc0
    const char* str = "grainStrength";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x126cd4
    sub_1AFCA4(...); // call internal at 0x126cf8
    const char* str = "mvpMatrix";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x126d54
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x126da0
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x126dc4
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x126de8
    glDrawArrays(...); // call PLT API at 0x126df8
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x126e08
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x126e18
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x126e28
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x126e38
    glBindFramebuffer(...); // call PLT API at 0x126e44
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x126e60
    const char* str = "FilterKernel";
    const char* str = "BindFBO fail-->CMTNoiseParticleFilter::FilterToFBO";
    __android_log_print(...); // call PLT API at 0x126e84
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x126ec4
}
