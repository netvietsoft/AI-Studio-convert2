// Function: MTFilterKernel::MTSoftHairFilter::grayFilterToFBO(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf42fc, Size: 260 bytes
int64_t _ZN14MTFilterKernel16MTSoftHairFilter15grayFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf4320
    glClear(...); // call PLT API at 0xf4328
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf4330
    glActiveTexture(...); // call PLT API at 0xf4338
    glBindTexture(...); // call PLT API at 0xf4344
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf435c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf4388
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf439c
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xf43a8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf43cc
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf43e0
    glDrawArrays(...); // call PLT API at 0xf43fc
}
