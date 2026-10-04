// Function: MTFilterKernel::MTCommonFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xd5220, Size: 444 bytes
int64_t _ZN14MTFilterKernel14MTCommonFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xd524c
    glClearColor(...); // call PLT API at 0xd5264
    glClear(...); // call PLT API at 0xd526c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xd5280
    (*x8)(...);
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xd52b4
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Common/MTCommonFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xd52ec
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xd5300
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xd5330
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xd5344
    glEnable(...); // call PLT API at 0xd5358
    glBlendFuncSeparate(...); // call PLT API at 0xd5378
    glBlendFunc(...); // call PLT API at 0xd538c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xd53ac
    glDisable(...); // call PLT API at 0xd53c0
    return a0;
}
