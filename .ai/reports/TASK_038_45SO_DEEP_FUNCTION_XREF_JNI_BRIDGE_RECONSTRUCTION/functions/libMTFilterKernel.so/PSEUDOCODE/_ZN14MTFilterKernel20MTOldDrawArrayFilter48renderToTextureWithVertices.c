// Function: MTFilterKernel::MTOldDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xf2194, Size: 580 bytes
int64_t _ZN14MTFilterKernel20MTOldDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf21c4
    glClearColor(...); // call PLT API at 0xf21d8
    glClear(...); // call PLT API at 0xf21e0
    _ZN14MTFilterKernel18MTCalTexCoordTools18GetDisPlayTexCoodsENS_16FilterKernelRectEi(...); // call internal at 0xf2224
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf2234
    _ZN14MTFilterKernel17MTDrawArrayFilter11bindTextureEv(...); // call internal at 0xf223c
    glActiveTexture(...); // call PLT API at 0xf2270
    glBindTexture(...); // call PLT API at 0xf227c
    glUniform1i(...); // call PLT API at 0xf2290
    _ZN14MTFilterKernel20MTOldDrawArrayFilter14changeFaceInfoEv(...); // call internal at 0xf2298
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv(...); // call internal at 0xf22a0
    (*x8)(...);
    glUniform1f(...); // call PLT API at 0xf22d0
    (*x8)(...);
    glUniform1f(...); // call PLT API at 0xf22f0
    glUniform1i(...); // call PLT API at 0xf2304
    glUniform1i(...); // call PLT API at 0xf2318
    glEnableVertexAttribArray(...); // call PLT API at 0xf2320
    glVertexAttribPointer(...); // call PLT API at 0xf233c
    glEnableVertexAttribArray(...); // call PLT API at 0xf2344
    glVertexAttribPointer(...); // call PLT API at 0xf2360
    glEnableVertexAttribArray(...); // call PLT API at 0xf236c
    glVertexAttribPointer(...); // call PLT API at 0xf2388
    glDrawArrays(...); // call PLT API at 0xf2398
    _ZdaPv(...); // call PLT API at 0xf23a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf23d4
}
