// Function: MTFilterKernel::GPUImageTwoPassFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x16bb34, Size: 744 bytes
int64_t _ZN14MTFilterKernel21GPUImageTwoPassFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0x16bbb8
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16bbc4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16bbcc
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x16bbec
    glClear(...); // call PLT API at 0x16bbf4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16bc0c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTOpenGL/GPUImage/GPUImageTwoPassFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16bc3c
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16bc54
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16bc7c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16bc94
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16bca8
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x16bcb0
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x16bcfc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x16bd04
    (*x8)(...);
    glClearColor(...); // call PLT API at 0x16bd24
    glClear(...); // call PLT API at 0x16bd2c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x16bd40
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16bd68
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16bd78
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x16bda0
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x16bdb0
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x16bdc4
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x16bde0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x16be18
}
