// Function: MTFilterKernel::MTSoftHairFilter::blurHFilterToFBO(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf4528, Size: 424 bytes
int64_t _ZN14MTFilterKernel16MTSoftHairFilter16blurHFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf4560
    glClear(...); // call PLT API at 0xf4568
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf45a8
    const char* str = "Weights";
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(...); // call internal at 0xf45c4
    const char* str = "Offsets";
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(...); // call internal at 0xf45e0
    glActiveTexture(...); // call PLT API at 0xf45e8
    glBindTexture(...); // call PLT API at 0xf45f4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf460c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf4638
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf464c
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xf4658
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf467c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf4690
    glDrawArrays(...); // call PLT API at 0xf46a0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf46cc
}
