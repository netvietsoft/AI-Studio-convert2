// Function: MTFilterKernel::FaceMaskFilter::ProcessGauss()
// RVA: 0x1200a8, Size: 648 bytes
int64_t _ZN14MTFilterKernel14FaceMaskFilter12ProcessGaussEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel14FaceMaskFilter7BindFBOEiii(...); // call internal at 0x1200d0
    glViewport(...); // call PLT API at 0x1200ec
    glUseProgram(...); // call PLT API at 0x1200f4
    glActiveTexture(...); // call PLT API at 0x1200fc
    glBindTexture(...); // call PLT API at 0x120108
    glUniform1i(...); // call PLT API at 0x120114
    glUniform1f(...); // call PLT API at 0x12014c
    glUniform1f(...); // call PLT API at 0x120158
    glEnableVertexAttribArray(...); // call PLT API at 0x120160
    glVertexAttribPointer(...); // call PLT API at 0x12017c
    glEnableVertexAttribArray(...); // call PLT API at 0x120184
    glVertexAttribPointer(...); // call PLT API at 0x1201a0
    glDrawArrays(...); // call PLT API at 0x1201b0
    _ZN14MTFilterKernel14FaceMaskFilter7BindFBOEiii(...); // call internal at 0x1201c0
    glViewport(...); // call PLT API at 0x1201dc
    glUseProgram(...); // call PLT API at 0x1201e4
    glActiveTexture(...); // call PLT API at 0x1201ec
    glBindTexture(...); // call PLT API at 0x1201f8
    glUniform1i(...); // call PLT API at 0x120204
    glUniform1f(...); // call PLT API at 0x120230
    glUniform1f(...); // call PLT API at 0x120248
    glEnableVertexAttribArray(...); // call PLT API at 0x120250
    glVertexAttribPointer(...); // call PLT API at 0x12026c
    glEnableVertexAttribArray(...); // call PLT API at 0x120274
    glVertexAttribPointer(...); // call PLT API at 0x120290
    glDrawArrays(...); // call PLT API at 0x1202a0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1202a8
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail 2";
    __android_log_print(...); // call PLT API at 0x1202e4
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1202e8
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail 3";
    __android_log_print(...); // call PLT API at 0x120308
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12032c
}
