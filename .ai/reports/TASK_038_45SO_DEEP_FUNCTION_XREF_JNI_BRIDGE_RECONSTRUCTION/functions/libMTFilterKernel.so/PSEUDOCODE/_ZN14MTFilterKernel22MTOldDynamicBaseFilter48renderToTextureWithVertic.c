// Function: MTFilterKernel::MTOldDynamicBaseFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0x1072d0, Size: 624 bytes
int64_t _ZN14MTFilterKernel22MTOldDynamicBaseFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x107344
    glClearColor(...); // call PLT API at 0x107350
    glClear(...); // call PLT API at 0x107358
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x107360
    (*x8)(...);
    const char* str = "alpha";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0x107390
    const char* str = "inputTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x1073a8
    sub_107540(...); // call internal at 0x1073e8
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x1073f4
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x10740c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/MTOldDynamicBaseFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x10743c
    const char* str = "aPosition";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x107450
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x107474
    const char* str = "aCameraVetexCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x107488
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0x1074b8
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/MTOldDynamicBaseFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x1074e0
    const char* str = "aTextCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x1074f4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x107508
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x10753c
}
