// Function: MTFilterKernel::MTBokehBlurDrawArrayFilter::bigMaskFilterToFBO(int, MTFilterKernel::GPUImageFramebuffer*, float)
// RVA: 0xeb298, Size: 344 bytes
int64_t _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18bigMaskFilterToFBOEiPNS_19GPUImageFramebufferEf(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xeb2c4
    glClear(...); // call PLT API at 0xeb2cc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xeb2d4
    const char* str = "textureWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb2ec
    const char* str = "textureHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb304
    const char* str = "radius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xeb31c
    glActiveTexture(...); // call PLT API at 0xeb324
    glBindTexture(...); // call PLT API at 0xeb330
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xeb348
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb378
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb38c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xeb3b4
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xeb3c8
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xeb3ec
}
