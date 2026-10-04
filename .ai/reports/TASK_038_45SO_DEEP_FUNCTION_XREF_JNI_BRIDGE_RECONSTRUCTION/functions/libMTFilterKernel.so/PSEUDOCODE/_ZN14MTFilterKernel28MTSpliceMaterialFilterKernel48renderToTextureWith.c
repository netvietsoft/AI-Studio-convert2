// Function: MTFilterKernel::MTSpliceMaterialFilterKernel::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0x112384, Size: 456 bytes
int64_t _ZN14MTFilterKernel28MTSpliceMaterialFilterKernel48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x1123ac
    glClearColor(...); // call PLT API at 0x1123b8
    glClear(...); // call PLT API at 0x1123c0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x1123d8
    (*x8)(...);
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x112404
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x112418
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/SpliceFilter/MTSpliceMaterialFilterKernel.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x112444
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x112458
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x11247c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x112490
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x1124c0
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x1124e4
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x1124f8
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x11250c
    return a0;
    _ZN14MTFilterKernel12MTFilterBase15copyFramebufferEPNS_15GPUImageContextEPNS_19GPUImageFramebufferES4_(...); // call internal at 0x112530
    return a0;
}
