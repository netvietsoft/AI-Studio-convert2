// Function: MTFilterKernel::GPUImageCMTOldDynamicFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x114f1c, Size: 720 bytes
int64_t _ZN14MTFilterKernel27GPUImageCMTOldDynamicFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x114fd4
    glClearColor(...); // call PLT API at 0x114fe0
    glClear(...); // call PLT API at 0x114fe8
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x114ff0
    (*x8)(...);
    const char* str = "alpha";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0x115024
    const char* str = "inputTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x11503c
    sub_1151EC(...); // call internal at 0x11507c
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x115088
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x1150a0
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/GPUImageCMTOldDynamicFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x1150d4
    const char* str = "aPosition";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x1150e8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x115110
    const char* str = "aCameraVetexCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x115124
    _ZN14MTFilterKernel14GPUImageFilter29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x115154
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/GPUImageCMTOldDynamicFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x11517c
    const char* str = "aTextCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x115190
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x1151a4
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1151e8
}
