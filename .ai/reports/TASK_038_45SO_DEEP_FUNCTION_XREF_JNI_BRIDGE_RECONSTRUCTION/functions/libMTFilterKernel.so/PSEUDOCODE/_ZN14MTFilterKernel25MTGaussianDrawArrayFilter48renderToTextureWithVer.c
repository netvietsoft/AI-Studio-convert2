// Function: MTFilterKernel::MTGaussianDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xf057c, Size: 780 bytes
int64_t _ZN14MTFilterKernel25MTGaussianDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xf05ec
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf05f4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf061c
    glActiveTexture(...); // call PLT API at 0xf0624
    glBindTexture(...); // call PLT API at 0xf0634
    const char* str = "inputImageTexture0";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf064c
    (*x8)(...);
    const char* str = "texelWidthOffset";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf06f8
    const char* str = "texelHeightOffset";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf0714
    glEnableVertexAttribArray(...); // call PLT API at 0xf071c
    glVertexAttribPointer(...); // call PLT API at 0xf0738
    glEnableVertexAttribArray(...); // call PLT API at 0xf0740
    glVertexAttribPointer(...); // call PLT API at 0xf075c
    glDrawArrays(...); // call PLT API at 0xf076c
    glFlush(...); // call PLT API at 0xf0770
    glBindFramebuffer(...); // call PLT API at 0xf077c
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf0784
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf078c
    glActiveTexture(...); // call PLT API at 0xf0794
    glBindTexture(...); // call PLT API at 0xf07a0
    glUniform1i(...); // call PLT API at 0xf07b0
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf07c4
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf07f0
    glEnableVertexAttribArray(...); // call PLT API at 0xf07f8
    glVertexAttribPointer(...); // call PLT API at 0xf0814
    glEnableVertexAttribArray(...); // call PLT API at 0xf081c
    glVertexAttribPointer(...); // call PLT API at 0xf0838
    glDrawArrays(...); // call PLT API at 0xf0848
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xf0850
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf0884
}
