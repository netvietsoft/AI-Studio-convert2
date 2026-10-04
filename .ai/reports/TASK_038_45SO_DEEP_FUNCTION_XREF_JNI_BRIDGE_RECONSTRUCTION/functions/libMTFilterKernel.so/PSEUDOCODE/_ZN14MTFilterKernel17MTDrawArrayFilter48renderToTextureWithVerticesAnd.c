// Function: MTFilterKernel::MTDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xedd00, Size: 540 bytes
int64_t _ZN14MTFilterKernel17MTDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xedd34
    (*x8)(...);
    (*x8)(...);
    sub_1AFCA4(...); // call internal at 0xedd80
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xeddf4
    _ZN14MTFilterKernel17MTDrawArrayFilter11bindTextureEv(...); // call internal at 0xeddfc
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv(...); // call internal at 0xede04
    glUniformMatrix4fv(...); // call PLT API at 0xede58
    glEnableVertexAttribArray(...); // call PLT API at 0xede60
    glVertexAttribPointer(...); // call PLT API at 0xede7c
    glEnableVertexAttribArray(...); // call PLT API at 0xede84
    glVertexAttribPointer(...); // call PLT API at 0xedea0
    glEnableVertexAttribArray(...); // call PLT API at 0xedeac
    glVertexAttribPointer(...); // call PLT API at 0xedec8
    glDrawArrays(...); // call PLT API at 0xeded8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xedf18
}
