// Function: MTFilterKernel::CMTStrokeFilter::LineFilterToFBO()
// RVA: 0x135b98, Size: 556 bytes
int64_t _ZN14MTFilterKernel15CMTStrokeFilter15LineFilterToFBOEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x135bc0
    glViewport(...); // call PLT API at 0x135bd4
    glUseProgram(...); // call PLT API at 0x135bdc
    glActiveTexture(...); // call PLT API at 0x135be4
    glBindTexture(...); // call PLT API at 0x135bf4
    glUniform1i(...); // call PLT API at 0x135c04
    glActiveTexture(...); // call PLT API at 0x135c0c
    glBindTexture(...); // call PLT API at 0x135c18
    glUniform1i(...); // call PLT API at 0x135c28
    (*x8)(...);
    glUniform1i(...); // call PLT API at 0x135c44
    _ZN14MTFilterKernel15setOrthoFrustumEffffff(...); // call internal at 0x135c6c
    glUniformMatrix4fv(...); // call PLT API at 0x135cc0
    glEnableVertexAttribArray(...); // call PLT API at 0x135cf0
    glVertexAttribPointer(...); // call PLT API at 0x135d0c
    glEnableVertexAttribArray(...); // call PLT API at 0x135d24
    glVertexAttribPointer(...); // call PLT API at 0x135d40
    glDrawArrays(...); // call PLT API at 0x135d50
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x135d58
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x135d98
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x135dc0
}
