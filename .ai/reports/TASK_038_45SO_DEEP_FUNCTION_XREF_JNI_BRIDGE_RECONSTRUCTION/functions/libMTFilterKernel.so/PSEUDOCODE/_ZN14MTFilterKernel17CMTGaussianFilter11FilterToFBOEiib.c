// Function: MTFilterKernel::CMTGaussianFilter::FilterToFBO(int, int, bool)
// RVA: 0x12095c, Size: 644 bytes
int64_t _ZN14MTFilterKernel17CMTGaussianFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel17CMTGaussianFilter11bindTempFBOEii(...); // call internal at 0x120990
    glViewport(...); // call PLT API at 0x1209a8
    glUseProgram(...); // call PLT API at 0x1209d0
    glActiveTexture(...); // call PLT API at 0x1209d8
    glBindTexture(...); // call PLT API at 0x1209e8
    glUniform1i(...); // call PLT API at 0x1209f4
    _ZN14MTFilterKernel17CMTGaussianFilter15refreshBlurSizeEv(...); // call internal at 0x1209fc
    glUniform1f(...); // call PLT API at 0x120a10
    glUniform1f(...); // call PLT API at 0x120a1c
    glEnableVertexAttribArray(...); // call PLT API at 0x120a24
    glVertexAttribPointer(...); // call PLT API at 0x120a40
    glEnableVertexAttribArray(...); // call PLT API at 0x120a48
    glVertexAttribPointer(...); // call PLT API at 0x120a64
    glDrawArrays(...); // call PLT API at 0x120a74
    glFlush(...); // call PLT API at 0x120a78
    glBindFramebuffer(...); // call PLT API at 0x120a84
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x120a94
    glViewport(...); // call PLT API at 0x120ab0
    glUseProgram(...); // call PLT API at 0x120ab8
    glActiveTexture(...); // call PLT API at 0x120ac0
    glBindTexture(...); // call PLT API at 0x120ad0
    glUniform1i(...); // call PLT API at 0x120ae0
    glUniform1f(...); // call PLT API at 0x120aec
    glUniform1f(...); // call PLT API at 0x120b04
    glEnableVertexAttribArray(...); // call PLT API at 0x120b0c
    glVertexAttribPointer(...); // call PLT API at 0x120b28
    glEnableVertexAttribArray(...); // call PLT API at 0x120b30
    glVertexAttribPointer(...); // call PLT API at 0x120b4c
    glDrawArrays(...); // call PLT API at 0x120b5c
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x120b68
    glDeleteTextures(...); // call PLT API at 0x120b7c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x120b8c
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x120bac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x120bdc
}
