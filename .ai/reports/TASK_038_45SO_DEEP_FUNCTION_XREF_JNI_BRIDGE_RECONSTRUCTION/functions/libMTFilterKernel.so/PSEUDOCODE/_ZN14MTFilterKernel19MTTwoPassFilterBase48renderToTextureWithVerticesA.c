// Function: MTFilterKernel::MTTwoPassFilterBase::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0x10dd8c, Size: 636 bytes
int64_t _ZN14MTFilterKernel19MTTwoPassFilterBase48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x10de18
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x10de20
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x10de40
    glClear(...); // call PLT API at 0x10de48
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x10de60
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/MTTwoPassFilterBase.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x10de8c
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x10dea4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x10dec8
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x10dee0
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x10def4
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x10defc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x10df04
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x10df24
    glClear(...); // call PLT API at 0x10df2c
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x10df3c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x10df64
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x10df74
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x10df9c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x10dfac
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x10dfc0
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x10dfc8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x10e004
}
