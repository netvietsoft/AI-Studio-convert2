// Function: MTFilterKernel::CMTNoiseColorOffsetFilter::FilterToFBO(int, int, bool)
// RVA: 0x121074, Size: 492 bytes
int64_t _ZN14MTFilterKernel25CMTNoiseColorOffsetFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x1210a8
    glViewport(...); // call PLT API at 0x1210c0
    glUseProgram(...); // call PLT API at 0x1210e8
    glActiveTexture(...); // call PLT API at 0x1210f0
    glBindTexture(...); // call PLT API at 0x121100
    glUniform1i(...); // call PLT API at 0x121110
    glUniform1f(...); // call PLT API at 0x12111c
    glUniform1f(...); // call PLT API at 0x121128
    glUniform1f(...); // call PLT API at 0x121134
    glUniform2f(...); // call PLT API at 0x121144
    glUniform1i(...); // call PLT API at 0x121150
    glUniform1f(...); // call PLT API at 0x12115c
    glUniform1f(...); // call PLT API at 0x121168
    glUniform2f(...); // call PLT API at 0x121178
    glEnableVertexAttribArray(...); // call PLT API at 0x121180
    glVertexAttribPointer(...); // call PLT API at 0x12119c
    glEnableVertexAttribArray(...); // call PLT API at 0x1211a4
    glVertexAttribPointer(...); // call PLT API at 0x1211c0
    glDrawArrays(...); // call PLT API at 0x1211d0
    glFlush(...); // call PLT API at 0x1211d4
    glBindFramebuffer(...); // call PLT API at 0x1211e0
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x1211ec
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x12120c
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x12122c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12125c
}
