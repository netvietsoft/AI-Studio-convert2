// Function: MTFilterKernel::GPUImageMyBoxFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x117e14, Size: 624 bytes
int64_t _ZN14MTFilterKernel19GPUImageMyBoxFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0x117e90
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x117eb8
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x117ec0
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x117ee0
    glClear(...); // call PLT API at 0x117ee8
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x117f04
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/GPUImageMyBoxFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x117f34
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x117f4c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x117f60
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x117f68
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x117fb4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x117fbc
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x117fdc
    glClear(...); // call PLT API at 0x117fe4
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x117ff4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x11801c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x11802c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x118040
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x118048
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x118080
}
