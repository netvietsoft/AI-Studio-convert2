// Function: MTFilterKernel::MTMyBoxFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0x105d7c, Size: 532 bytes
int64_t _ZN14MTFilterKernel13MTMyBoxFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x105e18
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x105e20
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x105e40
    glClear(...); // call PLT API at 0x105e48
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x105e60
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/MTMyBoxFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x105e8c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x105ea4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x105eb8
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x105ec0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x105ec8
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x105ee8
    glClear(...); // call PLT API at 0x105ef0
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x105f00
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x105f28
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x105f38
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x105f4c
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x105f54
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x105f8c
}
