// Function: MTFilterKernel::MTSoftHairFilter::hairMaskFilterToFBO(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf4400, Size: 296 bytes
int64_t _ZN14MTFilterKernel16MTSoftHairFilter19hairMaskFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf4424
    glClear(...); // call PLT API at 0xf442c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf4434
    const char* str = "shiftingSize";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xf4458
    glActiveTexture(...); // call PLT API at 0xf4460
    glBindTexture(...); // call PLT API at 0xf446c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf4484
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf44b0
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf44c4
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xf44d0
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf44f4
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf4508
    glDrawArrays(...); // call PLT API at 0xf4524
}
