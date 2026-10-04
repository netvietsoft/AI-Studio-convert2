// Function: MTFilterKernel::CMTXTDetailsFilter::FilterToFBO(int, int, bool)
// RVA: 0x133674, Size: 1528 bytes
int64_t _ZN14MTFilterKernel18CMTXTDetailsFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    glDeleteFramebuffers(...); // call PLT API at 0x133794
    glDeleteTextures(...); // call PLT API at 0x1337b0
    glDeleteTextures(...); // call PLT API at 0x1337cc
    glDeleteTextures(...); // call PLT API at 0x1337e8
    glDeleteTextures(...); // call PLT API at 0x133804
    _ZN14MTFilterKernel18CMTXTDetailsFilter4blurEjff(...); // call internal at 0x133824
    _ZN14MTFilterKernel18CMTXTDetailsFilter19drawWithBlurAndMaskEj(...); // call internal at 0x133834
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x1338a8
    _ZN14MTFilterKernel16CMTDynamicFilter19CopyTextureContentsEjj(...); // call internal at 0x1338bc
    glGetError(...); // call PLT API at 0x1338c0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1338cc
    const char* str = "FilterKernel";
    const char* str = "glGetError() = %i (0x%.8x) in filename = %s, line  = %i
";
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/OnlineFilter/Filters/MTXTDetailsFilter.cpp";
    __android_log_print(...); // call PLT API at 0x133900
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x133910
    glViewport(...); // call PLT API at 0x133924
    glUseProgram(...); // call PLT API at 0x13392c
    (*x8)(...);
    const char* str = "inputImageTexture";
    glGetUniformLocation(...); // call PLT API at 0x13396c
    const char* str = "inputImageMaskTexture";
    glGetUniformLocation(...); // call PLT API at 0x133984
    const char* str = "lastPassTexture";
    glGetUniformLocation(...); // call PLT API at 0x13399c
    const char* str = "blurImageTexture";
    glGetUniformLocation(...); // call PLT API at 0x1339b4
    const char* str = "colorR";
    glGetUniformLocation(...); // call PLT API at 0x1339cc
    const char* str = "colorG";
    glGetUniformLocation(...); // call PLT API at 0x1339e4
    const char* str = "colorB";
    glGetUniformLocation(...); // call PLT API at 0x1339fc
    const char* str = "colorA";
    glGetUniformLocation(...); // call PLT API at 0x133a14
    const char* str = "widthOffset";
    glGetUniformLocation(...); // call PLT API at 0x133a2c
    const char* str = "heightOffset";
    glGetUniformLocation(...); // call PLT API at 0x133a44
    const char* str = "inputTextureCoordinate";
    glGetAttribLocation(...); // call PLT API at 0x133a5c
    const char* str = "position";
    glGetAttribLocation(...); // call PLT API at 0x133a74
    glUniform1f(...); // call PLT API at 0x133a98
    glUniform1f(...); // call PLT API at 0x133ab0
    glUniform1f(...); // call PLT API at 0x133abc
    glUniform1f(...); // call PLT API at 0x133ac8
    glUniform1f(...); // call PLT API at 0x133ad4
    glUniform1f(...); // call PLT API at 0x133ae0
    glClearColor(...); // call PLT API at 0x133af4
    glEnableVertexAttribArray(...); // call PLT API at 0x133afc
    glVertexAttribPointer(...); // call PLT API at 0x133b18
    glEnableVertexAttribArray(...); // call PLT API at 0x133b20
    glVertexAttribPointer(...); // call PLT API at 0x133b3c
    glActiveTexture(...); // call PLT API at 0x133b44
    glBindTexture(...); // call PLT API at 0x133b54
    glUniform1i(...); // call PLT API at 0x133b60
    glActiveTexture(...); // call PLT API at 0x133b68
    glBindTexture(...); // call PLT API at 0x133b78
    glUniform1i(...); // call PLT API at 0x133b84
    glActiveTexture(...); // call PLT API at 0x133b8c
    glBindTexture(...); // call PLT API at 0x133b98
    glUniform1i(...); // call PLT API at 0x133ba4
    glActiveTexture(...); // call PLT API at 0x133bac
    glBindTexture(...); // call PLT API at 0x133bb8
    glUniform1i(...); // call PLT API at 0x133bc4
    glDrawArrays(...); // call PLT API at 0x133bd4
    glBindFramebuffer(...); // call PLT API at 0x133be0
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x133bfc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x133c04
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x133c24
    __stack_chk_fail(...); // call PLT API at 0x133c3c
}
