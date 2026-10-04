// Function: MTFilterKernel::MTBokehBlurDrawArrayFilter::mixFilterToFBO(int, int, int, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xeb6a0, Size: 360 bytes
int64_t _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter14mixFilterToFBOEiiiPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xeb6cc
    glClear(...); // call PLT API at 0xeb6d4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xeb6dc
    glActiveTexture(...); // call PLT API at 0xeb6e4
    glBindTexture(...); // call PLT API at 0xeb6f0
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb708
    glActiveTexture(...); // call PLT API at 0xeb710
    glBindTexture(...); // call PLT API at 0xeb71c
    const char* str = "gradientTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb734
    glActiveTexture(...); // call PLT API at 0xeb73c
    glBindTexture(...); // call PLT API at 0xeb748
    const char* str = "bodyMaskTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb760
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb790
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb7a4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb7cc
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb7e0
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xeb804
}
