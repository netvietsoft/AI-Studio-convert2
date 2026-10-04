// Function: MTFilterKernel::MTSoftHairFilter::softHairFilterToFBO(float const*, float const*, int, int, int, MTFilterKernel::CGSize, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf4878, Size: 564 bytes
int64_t _ZN14MTFilterKernel16MTSoftHairFilter19softHairFilterToFBOEPKfS2_iiiNS_6CGSizeEPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf48c8
    glClear(...); // call PLT API at 0xf48d0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf48f0
    const char* str = "threshold";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf4908
    const char* str = "gain";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf4920
    const char* str = "shiftingSize";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb(...); // call internal at 0xf4940
    const char* str = "kernel";
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib(...); // call internal at 0xf495c
    glActiveTexture(...); // call PLT API at 0xf4964
    glBindTexture(...); // call PLT API at 0xf4970
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf4988
    glActiveTexture(...); // call PLT API at 0xf4990
    glBindTexture(...); // call PLT API at 0xf499c
    const char* str = "gradientTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf49b4
    glActiveTexture(...); // call PLT API at 0xf49bc
    glBindTexture(...); // call PLT API at 0xf49c8
    const char* str = "hairMaskTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf49e0
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf4a0c
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf4a20
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE(...); // call internal at 0xf4a2c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf4a50
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf4a64
    glDrawArrays(...); // call PLT API at 0xf4a74
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf4aa8
}
