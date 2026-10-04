// Function: MTFilterKernel::MTBokehDrawArrayFilter::renderToTextureWithVerticesAndTextureCoordinates(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::MTImgTextureManger const&)
// RVA: 0xebd50, Size: 1804 bytes
int64_t _ZN14MTFilterKernel22MTBokehDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel17MTDrawArrayFilter24ScaleLengthByMinimueEdgeEiiiRiS1_(...); // call internal at 0xebe64
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xebeac
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xebeec
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xebef8
    glClear(...); // call PLT API at 0xebf00
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xebf08
    glActiveTexture(...); // call PLT API at 0xebf10
    glBindTexture(...); // call PLT API at 0xebf20
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xebf38
    glActiveTexture(...); // call PLT API at 0xebf48
    glBindTexture(...); // call PLT API at 0xebf58
    const char* str = "fabbyMask";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xebf70
    glActiveTexture(...); // call PLT API at 0xebf94
    const char* str = "direction";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xebfc0
    const char* str = "textureWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xebfd8
    const char* str = "textureHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xebff0
    sinf(...); // call PLT API at 0xec00c
    const char* str = "textureOffsetDegree";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xec020
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec054
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec06c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec094
    const char* str = "texcoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec0ac
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xec0c0
    const char* str = "texture";
    glActiveTexture(...); // call PLT API at 0xec0f4
    glBindTexture(...); // call PLT API at 0xec104
    const char* str = "fabbyMask";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xec11c
    const char* str = "direction";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xec138
    const char* str = "textureWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xec150
    const char* str = "textureHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xec168
    sinf(...); // call PLT API at 0xec178
    const char* str = "textureOffsetDegree";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xec18c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec1b4
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec1c4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec1ec
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec1fc
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xec210
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xec230
    glClear(...); // call PLT API at 0xec238
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xec240
    glActiveTexture(...); // call PLT API at 0xec248
    glBindTexture(...); // call PLT API at 0xec258
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xec26c
    glActiveTexture(...); // call PLT API at 0xec294
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xec2ac
    glClear(...); // call PLT API at 0xec2b4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xec2bc
    glActiveTexture(...); // call PLT API at 0xec2c4
    glBindTexture(...); // call PLT API at 0xec2d4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xec2ec
    glActiveTexture(...); // call PLT API at 0xec2f4
    glBindTexture(...); // call PLT API at 0xec304
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xec31c
    glActiveTexture(...); // call PLT API at 0xec324
    glBindTexture(...); // call PLT API at 0xec330
    const char* str = "maskTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xec348
    const char* str = "alpha";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xec37c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec3a8
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec3bc
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xec3e0
    const char* str = "texcoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xec3f4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xec408
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xec410
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xec418
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xec458
}
