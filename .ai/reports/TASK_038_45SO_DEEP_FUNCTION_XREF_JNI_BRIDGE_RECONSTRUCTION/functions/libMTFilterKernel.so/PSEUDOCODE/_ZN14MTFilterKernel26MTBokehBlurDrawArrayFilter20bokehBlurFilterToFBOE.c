// Function: MTFilterKernel::MTBokehBlurDrawArrayFilter::bokehBlurFilterToFBO(int, int, int, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xeb3f0, Size: 688 bytes
int64_t _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter20bokehBlurFilterToFBOEiiiPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xeb434
    glClear(...); // call PLT API at 0xeb43c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xeb444
    const char* str = "imageheight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb45c
    const char* str = "imagewidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb474
    const char* str = "maskradius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb48c
    const char* str = "farDepth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb4ac
    const char* str = "nearDepth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb4c4
    const char* str = "farRadius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb4dc
    const char* str = "nearRadius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb4f4
    const char* str = "highlights";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb50c
    const char* str = "vivid";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb524
    const char* str = "mattebox";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb53c
    glActiveTexture(...); // call PLT API at 0xeb564
    glBindTexture(...); // call PLT API at 0xeb570
    const char* str = "inputImage";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb588
    glActiveTexture(...); // call PLT API at 0xeb590
    glBindTexture(...); // call PLT API at 0xeb59c
    const char* str = "diaphragmImage";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb5b4
    glActiveTexture(...); // call PLT API at 0xeb5bc
    glBindTexture(...); // call PLT API at 0xeb5c8
    const char* str = "maskResult";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb5e0
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb60c
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb620
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb644
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb658
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xeb66c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xeb69c
}
