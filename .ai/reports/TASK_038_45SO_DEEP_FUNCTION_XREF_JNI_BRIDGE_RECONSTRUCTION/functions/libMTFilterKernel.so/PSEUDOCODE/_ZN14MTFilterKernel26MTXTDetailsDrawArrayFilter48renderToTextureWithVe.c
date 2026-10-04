// Function: MTFilterKernel::MTXTDetailsDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xf7098, Size: 956 bytes
int64_t _ZN14MTFilterKernel26MTXTDetailsDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0xf70d0
    const char* str = "FilterKernel";
    const char* str = "MTXTDetailsDrawArrayFilter _inputTextureIDArray.size() < 2 return";
    __android_log_print(...); // call PLT API at 0xf70f0
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xf7144
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xf7184
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel26MTXTDetailsDrawArrayFilter4blurEjff(...); // call internal at 0xf71c4
    _ZN14MTFilterKernel26MTXTDetailsDrawArrayFilter19drawWithBlurAndMaskEj(...); // call internal at 0xf71d4
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf71dc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf71e4
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv(...); // call internal at 0xf720c
    (*x8)(...);
    const char* str = "widthOffset";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf723c
    (*x8)(...);
    const char* str = "heightOffset";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf7268
    const char* str = "colorR";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf7280
    const char* str = "colorG";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf7298
    const char* str = "colorB";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf72b0
    const char* str = "colorA";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf72c8
    glClearColor(...); // call PLT API at 0xf72dc
    glEnableVertexAttribArray(...); // call PLT API at 0xf72e4
    glVertexAttribPointer(...); // call PLT API at 0xf7300
    glEnableVertexAttribArray(...); // call PLT API at 0xf7308
    glVertexAttribPointer(...); // call PLT API at 0xf7324
    glActiveTexture(...); // call PLT API at 0xf732c
    glBindTexture(...); // call PLT API at 0xf733c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf7354
    glActiveTexture(...); // call PLT API at 0xf735c
    glBindTexture(...); // call PLT API at 0xf736c
    const char* str = "inputImageMaskTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf7384
    glActiveTexture(...); // call PLT API at 0xf738c
    glBindTexture(...); // call PLT API at 0xf739c
    const char* str = "blurImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf73b4
    glActiveTexture(...); // call PLT API at 0xf73bc
    glBindTexture(...); // call PLT API at 0xf73cc
    const char* str = "lastPassTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf73e4
    glDrawArrays(...); // call PLT API at 0xf73f4
    glBindFramebuffer(...); // call PLT API at 0xf7400
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xf7414
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xf741c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf7450
}
