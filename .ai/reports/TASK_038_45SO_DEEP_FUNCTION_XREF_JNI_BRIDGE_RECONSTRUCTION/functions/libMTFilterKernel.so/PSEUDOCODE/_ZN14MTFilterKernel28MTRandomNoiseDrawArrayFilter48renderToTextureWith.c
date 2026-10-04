// Function: MTFilterKernel::MTRandomNoiseDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xf3068, Size: 840 bytes
int64_t _ZN14MTFilterKernel28MTRandomNoiseDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel17MTDrawArrayFilter24ScaleLengthByMinimueEdgeEiiiRiS1_(...); // call internal at 0xf30d0
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xf3110
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf3118
    glClear(...); // call PLT API at 0xf3120
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf31c4
    glActiveTexture(...); // call PLT API at 0xf31cc
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTRandomNoiseDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf31f8
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf3210
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf3234
    const char* str = "texcoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf324c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xf3260
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf3268
    glClear(...); // call PLT API at 0xf3270
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf3278
    glActiveTexture(...); // call PLT API at 0xf3280
    glBindTexture(...); // call PLT API at 0xf3290
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf32a8
    glActiveTexture(...); // call PLT API at 0xf32b0
    glBindTexture(...); // call PLT API at 0xf32bc
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf32d4
    const char* str = "degree";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf32ec
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf3314
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf3324
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf334c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf335c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xf3370
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xf3378
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf33ac
}
