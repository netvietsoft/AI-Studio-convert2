// Function: MTFilterKernel::GPUImageFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*)
// RVA: 0x161a44, Size: 416 bytes
int64_t _ZN14MTFilterKernel14GPUImageFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x161ac0
    glClearColor(...); // call PLT API at 0x161acc
    glClear(...); // call PLT API at 0x161ad4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0x161adc
    (*x8)(...);
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0x161b08
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTOpenGL/GPUImage/GPUImageFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x161b38
    const char* str = "position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x161b4c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0x161b74
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0x161b88
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0x161b9c
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x161be0
}
