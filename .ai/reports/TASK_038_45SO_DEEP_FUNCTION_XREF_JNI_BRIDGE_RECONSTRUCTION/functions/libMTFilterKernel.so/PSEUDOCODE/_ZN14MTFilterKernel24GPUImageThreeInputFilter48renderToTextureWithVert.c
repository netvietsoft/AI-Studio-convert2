// Function: MTFilterKernel::GPUImageThreeInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x169f84, Size: 752 bytes
int64_t _ZN14MTFilterKernel24GPUImageThreeInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16a00c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16a020
    (*x9)(...);
    glClearColor(...); // call PLT API at 0x16a054
    glClear(...); // call PLT API at 0x16a05c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16a080
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16a0a8
    const char* str = "inputImageTexture3";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16a0c8
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTOpenGL/GPUImage/GPUImageThreeInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16a104
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16a118
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16a14c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16a160
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x16a180
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16a1a4
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16a1b8
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x16a1d4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16a1f8
    const char* str = "inputTextureCoordinate3";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16a20c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16a22c
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x16a270
}
