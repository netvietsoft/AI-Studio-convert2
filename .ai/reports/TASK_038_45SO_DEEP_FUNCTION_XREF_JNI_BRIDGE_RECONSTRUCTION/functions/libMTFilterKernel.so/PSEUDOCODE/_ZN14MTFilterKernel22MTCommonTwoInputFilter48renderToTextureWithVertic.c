// Function: MTFilterKernel::MTCommonTwoInputFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xd60c0, Size: 556 bytes
int64_t _ZN14MTFilterKernel22MTCommonTwoInputFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xd60e8
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xd60fc
    (*x8)(...);
    glClearColor(...); // call PLT API at 0xd6128
    glClear(...); // call PLT API at 0xd6130
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xd6154
    const char* str = "inputImageTexture2";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xd6174
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Common/MTCommonTwoInputFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xd61ac
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xd61c0
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xd61f0
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xd6204
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xd621c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xd6240
    const char* str = "inputTextureCoordinate2";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xd6254
    glEnable(...); // call PLT API at 0xd6268
    glBlendFuncSeparate(...); // call PLT API at 0xd6288
    glBlendFunc(...); // call PLT API at 0xd629c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xd62bc
    glDisable(...); // call PLT API at 0xd62d0
    return a0;
}
