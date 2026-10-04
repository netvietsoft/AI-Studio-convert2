// Function: MTFilterKernel::MTBokehBlurDrawArrayFilter::scalingFilterToFBO(int, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xeb034, Size: 256 bytes
int64_t _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xeb054
    glClear(...); // call PLT API at 0xeb05c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xeb064
    glActiveTexture(...); // call PLT API at 0xeb06c
    glBindTexture(...); // call PLT API at 0xeb078
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb090
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb0c0
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb0d4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb0fc
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb110
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xeb130
}
