// Function: MTFilterKernel::CMTDynamicFilter::FilterToFBO(int, int, bool)
// RVA: 0x11d630, Size: 1148 bytes
int64_t _ZN14MTFilterKernel16CMTDynamicFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x11d700
    glDeleteTextures(...); // call PLT API at 0x11d71c
    glDeleteTextures(...); // call PLT API at 0x11d738
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x11d7b0
    _ZN14MTFilterKernel16CMTDynamicFilter19CopyTextureContentsEjj(...); // call internal at 0x11d7c4
    glGetError(...); // call PLT API at 0x11d7c8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11d7d4
    const char* str = "FilterKernel";
    const char* str = "glGetError() = %i (0x%.8x) in filename = %s, line  = %i
";
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/OnlineFilter/CommonFilter/MTDynamicFilter.cpp";
    __android_log_print(...); // call PLT API at 0x11d808
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x11d818
    glViewport(...); // call PLT API at 0x11d82c
    sub_1AFCA4(...); // call internal at 0x11d854
    glUseProgram(...); // call PLT API at 0x11d894
    (*x8)(...);
    (*x8)(...);
    glUniformMatrix4fv(...); // call PLT API at 0x11d908
    glEnableVertexAttribArray(...); // call PLT API at 0x11d910
    glVertexAttribPointer(...); // call PLT API at 0x11d92c
    glEnableVertexAttribArray(...); // call PLT API at 0x11d934
    glVertexAttribPointer(...); // call PLT API at 0x11d950
    glEnableVertexAttribArray(...); // call PLT API at 0x11d95c
    glVertexAttribPointer(...); // call PLT API at 0x11d978
    glDrawArrays(...); // call PLT API at 0x11d988
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x11d9a4
    _ZdaPv(...); // call PLT API at 0x11d9b4
    _Znam(...); // call PLT API at 0x11d9d4
    glReadPixels(...); // call PLT API at 0x11d9f8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x11da10
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x11da30
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x11daa8
}
