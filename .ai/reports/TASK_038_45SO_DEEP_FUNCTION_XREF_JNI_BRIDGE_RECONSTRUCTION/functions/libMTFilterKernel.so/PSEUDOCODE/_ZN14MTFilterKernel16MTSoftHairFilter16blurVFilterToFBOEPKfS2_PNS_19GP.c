// Function: MTFilterKernel::MTSoftHairFilter::blurVFilterToFBO(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf46d0, Size: 424 bytes
int64_t _ZN14MTFilterKernel16MTSoftHairFilter16blurVFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf4708
    glClear(...); // call PLT API at 0xf4710
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf4750
    const char* str = "Weights";
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(...); // call internal at 0xf476c
    const char* str = "Offsets";
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(...); // call internal at 0xf4788
    glActiveTexture(...); // call PLT API at 0xf4790
    glBindTexture(...); // call PLT API at 0xf479c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf47b4
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf47e0
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf47f4
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xf4800
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf4824
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf4838
    glDrawArrays(...); // call PLT API at 0xf4848
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf4874
}
