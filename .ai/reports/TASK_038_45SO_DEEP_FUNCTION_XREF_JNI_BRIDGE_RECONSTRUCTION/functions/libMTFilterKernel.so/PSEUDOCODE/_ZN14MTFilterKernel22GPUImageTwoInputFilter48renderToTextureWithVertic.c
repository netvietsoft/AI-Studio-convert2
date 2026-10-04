// Function: MTFilterKernel::GPUImageTwoInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x16ae28, Size: 624 bytes
int64_t _ZN14MTFilterKernel22GPUImageTwoInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16aeb0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16aec4
    (*x9)(...);
    glClearColor(...); // call PLT API at 0x16aef8
    glClear(...); // call PLT API at 0x16af00
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16af24
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16af44
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTOpenGL/GPUImage/GPUImageTwoInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16af80
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16af94
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16afc8
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16afdc
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x16aff8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16b01c
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16b030
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16b050
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x16b094
}
