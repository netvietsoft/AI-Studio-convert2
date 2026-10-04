// Function: MTFilterKernel::GPUImageCommonThreeInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0xc9954, Size: 836 bytes
int64_t _ZN14MTFilterKernel30GPUImageCommonThreeInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xc99dc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xc99f0
    (*x8)(...);
    glClearColor(...); // call PLT API at 0xc9a1c
    glClear(...); // call PLT API at 0xc9a24
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xc9a48
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xc9a70
    const char* str = "inputImageTexture3";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xc9a90
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/Common/GPUImageCommonThreeInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc9acc
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc9ae0
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc9b14
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc9b28
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xc9b48
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc9b6c
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc9b80
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xc9b9c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xc9bc0
    const char* str = "inputTextureCoordinate3";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xc9bd4
    glEnable(...); // call PLT API at 0xc9be8
    glBlendFuncSeparate(...); // call PLT API at 0xc9c08
    glBlendFunc(...); // call PLT API at 0xc9c1c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xc9c3c
    glDisable(...); // call PLT API at 0xc9c50
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc9c94
}
