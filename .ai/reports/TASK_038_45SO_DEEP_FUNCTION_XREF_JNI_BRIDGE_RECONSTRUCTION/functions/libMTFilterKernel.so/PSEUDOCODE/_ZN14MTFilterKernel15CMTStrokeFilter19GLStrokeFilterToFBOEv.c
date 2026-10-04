// Function: MTFilterKernel::CMTStrokeFilter::GLStrokeFilterToFBO()
// RVA: 0x135994, Size: 516 bytes
int64_t _ZN14MTFilterKernel15CMTStrokeFilter19GLStrokeFilterToFBOEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x1359bc
    _ZN14MTFilterKernel15setOrthoFrustumEffffff(...); // call internal at 0x1359e8
    glViewport(...); // call PLT API at 0x1359f8
    glUseProgram(...); // call PLT API at 0x135a00
    (*x8)(...);
    (*x8)(...);
    glUniformMatrix4fv(...); // call PLT API at 0x135a74
    glUniform1f(...); // call PLT API at 0x135a84
    glUniform1f(...); // call PLT API at 0x135a94
    glEnableVertexAttribArray(...); // call PLT API at 0x135ac4
    glVertexAttribPointer(...); // call PLT API at 0x135ae0
    glEnableVertexAttribArray(...); // call PLT API at 0x135af8
    glVertexAttribPointer(...); // call PLT API at 0x135b14
    glDrawArrays(...); // call PLT API at 0x135b24
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x135b2c
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x135b6c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x135b94
}
