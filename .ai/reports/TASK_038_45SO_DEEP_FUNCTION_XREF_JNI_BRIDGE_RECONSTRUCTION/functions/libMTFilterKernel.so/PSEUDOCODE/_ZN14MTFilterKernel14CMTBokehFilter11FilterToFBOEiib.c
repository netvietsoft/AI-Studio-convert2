// Function: MTFilterKernel::CMTBokehFilter::FilterToFBO(int, int, bool)
// RVA: 0x1239c0, Size: 1608 bytes
int64_t _ZN14MTFilterKernel14CMTBokehFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x123a34
    glDeleteTextures(...); // call PLT API at 0x123a50
    glDeleteFramebuffers(...); // call PLT API at 0x123a6c
    glDeleteTextures(...); // call PLT API at 0x123a88
    (*x8)(...);
    (*x8)(...);
    glClear(...); // call PLT API at 0x123adc
    glViewport(...); // call PLT API at 0x123aec
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x123af4
    glActiveTexture(...); // call PLT API at 0x123afc
    glBindTexture(...); // call PLT API at 0x123b0c
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123b20
    glActiveTexture(...); // call PLT API at 0x123b30
    glBindTexture(...); // call PLT API at 0x123b40
    const char* str = "fabbyMask";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123b54
    glActiveTexture(...); // call PLT API at 0x123b78
    const char* str = "direction";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x123b9c
    const char* str = "textureWidth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123bb4
    const char* str = "textureHeight";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123bcc
    sinf(...); // call PLT API at 0x123be8
    const char* str = "textureOffsetDegree";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123bfc
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123c24
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123c4c
    glDrawArrays(...); // call PLT API at 0x123c60
    (*x8)(...);
    const char* str = "texture";
    glActiveTexture(...); // call PLT API at 0x123c94
    glBindTexture(...); // call PLT API at 0x123ca4
    const char* str = "fabbyMask";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123cb8
    const char* str = "direction";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x123cd0
    const char* str = "textureWidth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123ce8
    const char* str = "textureHeight";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123d00
    sinf(...); // call PLT API at 0x123d10
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123d1c
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123d3c
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123d5c
    glDrawArrays(...); // call PLT API at 0x123d6c
    (*x8)(...);
    (*x8)(...);
    glClear(...); // call PLT API at 0x123da4
    glViewport(...); // call PLT API at 0x123db4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x123dbc
    glActiveTexture(...); // call PLT API at 0x123dc4
    glBindTexture(...); // call PLT API at 0x123dd0
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123de0
    glActiveTexture(...); // call PLT API at 0x123e08
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x123e18
    const char* str = "FilterKernel";
    const char* str = "bind blur fbo failed";
    __android_log_print(...); // call PLT API at 0x123e38
    return a0;
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x123e80
    glViewport(...); // call PLT API at 0x123e94
    glClear(...); // call PLT API at 0x123e9c
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x123ea4
    glActiveTexture(...); // call PLT API at 0x123eac
    glBindTexture(...); // call PLT API at 0x123ebc
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123ed0
    glActiveTexture(...); // call PLT API at 0x123ed8
    glBindTexture(...); // call PLT API at 0x123ee4
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123ef8
    glActiveTexture(...); // call PLT API at 0x123f00
    glBindTexture(...); // call PLT API at 0x123f0c
    const char* str = "maskTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123f20
    const char* str = "alpha";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123f50
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123f74
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123f98
    glDrawArrays(...); // call PLT API at 0x123fa8
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x123fb8
    __stack_chk_fail(...); // call PLT API at 0x123fe4
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x123fe8
    const char* str = "FilterKernel";
    const char* str = "bind fbo fail";
}
