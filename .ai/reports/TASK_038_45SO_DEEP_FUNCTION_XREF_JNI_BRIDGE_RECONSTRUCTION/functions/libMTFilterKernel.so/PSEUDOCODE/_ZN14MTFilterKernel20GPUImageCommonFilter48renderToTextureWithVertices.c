// Function: MTFilterKernel::GPUImageCommonFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0xc8638, Size: 600 bytes
int64_t _ZN14MTFilterKernel20GPUImageCommonFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xc86c0
    glClearColor(...); // call PLT API at 0xc86d8
    glClear(...); // call PLT API at 0xc86e0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xc86f4
    (*x8)(...);
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xc872c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/Common/GPUImageCommonFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc8768
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc877c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc87b0
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc87c4
    glEnable(...); // call PLT API at 0xc87d8
    glBlendFuncSeparate(...); // call PLT API at 0xc87f8
    glBlendFunc(...); // call PLT API at 0xc880c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xc882c
    glDisable(...); // call PLT API at 0xc8840
    (*x9)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc888c
}
