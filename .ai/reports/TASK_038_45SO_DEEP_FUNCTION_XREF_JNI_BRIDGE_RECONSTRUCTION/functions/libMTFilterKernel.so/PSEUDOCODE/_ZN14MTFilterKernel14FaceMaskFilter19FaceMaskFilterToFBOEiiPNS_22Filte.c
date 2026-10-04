// Function: MTFilterKernel::FaceMaskFilter::FaceMaskFilterToFBO(int, int, MTFilterKernel::FilterkernelNativeFace*)
// RVA: 0x11fe80, Size: 552 bytes
int64_t _ZN14MTFilterKernel14FaceMaskFilter19FaceMaskFilterToFBOEiiPNS_22FilterkernelNativeFaceE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel14FaceMaskFilter7BindFBOEiii(...); // call internal at 0x11ff40
    glViewport(...); // call PLT API at 0x11ff64
    glUseProgram(...); // call PLT API at 0x11ff8c
    glUniform1f(...); // call PLT API at 0x11ff98
    glUniform1f(...); // call PLT API at 0x11ffa8
    glUniform1f(...); // call PLT API at 0x11ffb4
    glUniform1f(...); // call PLT API at 0x11ffc0
    glUniform1f(...); // call PLT API at 0x11ffd4
    glUniform1f(...); // call PLT API at 0x11ffe8
    glEnableVertexAttribArray(...); // call PLT API at 0x11fff0
    glVertexAttribPointer(...); // call PLT API at 0x12000c
    glEnableVertexAttribArray(...); // call PLT API at 0x120014
    glVertexAttribPointer(...); // call PLT API at 0x120030
    glDrawArrays(...); // call PLT API at 0x120040
    _ZN14MTFilterKernel14FaceMaskFilter12ProcessGaussEv(...); // call internal at 0x120048
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x120054
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail 1";
    __android_log_print(...); // call PLT API at 0x120074
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1200a4
}
