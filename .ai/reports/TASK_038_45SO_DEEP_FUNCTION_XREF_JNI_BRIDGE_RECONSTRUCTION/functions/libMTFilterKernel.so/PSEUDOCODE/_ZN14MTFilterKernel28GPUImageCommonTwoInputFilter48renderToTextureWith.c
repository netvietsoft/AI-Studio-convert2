// Function: MTFilterKernel::GPUImageCommonTwoInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0xca72c, Size: 708 bytes
int64_t _ZN14MTFilterKernel28GPUImageCommonTwoInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xca7b4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xca7c8
    (*x8)(...);
    glClearColor(...); // call PLT API at 0xca7f4
    glClear(...); // call PLT API at 0xca7fc
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xca820
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xca840
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/Common/GPUImageCommonTwoInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xca87c
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xca890
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xca8c4
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xca8d8
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xca8f4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xca918
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xca92c
    glEnable(...); // call PLT API at 0xca940
    glBlendFuncSeparate(...); // call PLT API at 0xca960
    glBlendFunc(...); // call PLT API at 0xca974
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xca994
    glDisable(...); // call PLT API at 0xca9a8
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xca9ec
}
