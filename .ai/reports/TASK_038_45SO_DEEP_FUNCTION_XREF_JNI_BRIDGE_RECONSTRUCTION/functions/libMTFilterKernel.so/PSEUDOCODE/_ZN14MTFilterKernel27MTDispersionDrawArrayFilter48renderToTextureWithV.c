// Function: MTFilterKernel::MTDispersionDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xecd88, Size: 364 bytes
int64_t _ZN14MTFilterKernel27MTDispersionDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel27MTDispersionDrawArrayFilter16updateParametersEv(...); // call internal at 0xecdb0
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xecdd8
    glClear(...); // call PLT API at 0xecde0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xecde8
    glActiveTexture(...); // call PLT API at 0xecdf0
    glBindTexture(...); // call PLT API at 0xece00
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xece18
    const char* str = "prismR";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xece30
    const char* str = "refraction";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xece50
    const char* str = "coordinate";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xece6c
    glEnableVertexAttribArray(...); // call PLT API at 0xece74
    glVertexAttribPointer(...); // call PLT API at 0xece90
    glEnableVertexAttribArray(...); // call PLT API at 0xece98
    glVertexAttribPointer(...); // call PLT API at 0xeceb4
    glDrawArrays(...); // call PLT API at 0xecec4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xecef0
}
