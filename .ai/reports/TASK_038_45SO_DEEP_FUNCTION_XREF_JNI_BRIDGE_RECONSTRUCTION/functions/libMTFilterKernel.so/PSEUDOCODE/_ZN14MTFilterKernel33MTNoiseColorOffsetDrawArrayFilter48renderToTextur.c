// Function: MTFilterKernel::MTNoiseColorOffsetDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xf13d8, Size: 648 bytes
int64_t _ZN14MTFilterKernel33MTNoiseColorOffsetDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf1408
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf1430
    glActiveTexture(...); // call PLT API at 0xf1438
    glBindTexture(...); // call PLT API at 0xf1448
    glUniform1i(...); // call PLT API at 0xf1458
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf1484
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf14b8
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf14f4
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xf151c
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf1540
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf1564
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf1588
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xf15b0
    glEnableVertexAttribArray(...); // call PLT API at 0xf15b8
    glVertexAttribPointer(...); // call PLT API at 0xf15d4
    glEnableVertexAttribArray(...); // call PLT API at 0xf15dc
    glVertexAttribPointer(...); // call PLT API at 0xf15f8
    glDrawArrays(...); // call PLT API at 0xf1608
    glFlush(...); // call PLT API at 0xf160c
    glBindFramebuffer(...); // call PLT API at 0xf1618
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf165c
}
