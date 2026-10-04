// Function: MTFilterKernel::GPUImageTwoPassTwoInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x16ce9c, Size: 1128 bytes
int64_t _ZN14MTFilterKernel29GPUImageTwoPassTwoInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0x16cf2c
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16cf38
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16cf4c
    (*x9)(...);
    glClearColor(...); // call PLT API at 0x16cf80
    glClear(...); // call PLT API at 0x16cf88
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16cfac
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16cfcc
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTOpenGL/GPUImage/GPUImageTwoPassTwoInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d008
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d020
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d054
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d06c
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x16d088
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d0ac
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d0c4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16d0e4
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x16d0f8
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16d154
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16d15c
    (*x9)(...);
    glClearColor(...); // call PLT API at 0x16d190
    glClear(...); // call PLT API at 0x16d198
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16d1ac
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16d1c4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d1f8
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d208
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d23c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d24c
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x16d268
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16d28c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16d29c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16d2b0
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x16d2b8
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x16d2c0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x16d300
}
