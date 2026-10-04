// Function: MTFilterKernel::MTSimpleDefocusFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xe8f34, Size: 1264 bytes
int64_t _ZN14MTFilterKernel21MTSimpleDefocusFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xe9030
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xe9038
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xe9040
    (*x8)(...);
    const char* str = "texelWidthOffset";
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xe9068
    glUniform1f(...); // call PLT API at 0xe9070
    const char* str = "texelHeightOffset";
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xe9084
    glUniform1f(...); // call PLT API at 0xe9090
    glClearColor(...); // call PLT API at 0xe909c
    glClear(...); // call PLT API at 0xe90a4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xe90bc
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTSimpleDefocusFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe90e8
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe90fc
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xe9108
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe912c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe9140
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xe9154
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0xe9184
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xe918c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xe9194
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xe91b4
    glUniform1f(...); // call PLT API at 0xe91c0
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0xe91cc
    glUniform1f(...); // call PLT API at 0xe91d4
    glClearColor(...); // call PLT API at 0xe91e0
    glClear(...); // call PLT API at 0xe91e8
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xe91f8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe9220
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe9238
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xe9248
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe926c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe9288
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xe929c
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xe92a4
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xe92ac
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xe92b4
    (*x8)(...);
    glClearColor(...); // call PLT API at 0xe92d4
    glClear(...); // call PLT API at 0xe92dc
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xe92ec
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xe9300
    const char* str = "inputImageTexture3";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xe9314
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe933c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe934c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe9378
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe9388
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xe93b0
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xe93c4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xe93d8
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xe93e0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe9420
}
