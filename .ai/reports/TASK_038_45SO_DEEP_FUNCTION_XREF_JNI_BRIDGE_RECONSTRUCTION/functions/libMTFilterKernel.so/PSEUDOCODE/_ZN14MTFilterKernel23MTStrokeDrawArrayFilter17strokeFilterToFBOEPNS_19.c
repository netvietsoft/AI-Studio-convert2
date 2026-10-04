// Function: MTFilterKernel::MTStrokeDrawArrayFilter::strokeFilterToFBO(MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf52c8, Size: 628 bytes
int64_t _ZN14MTFilterKernel23MTStrokeDrawArrayFilter17strokeFilterToFBOEPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf52f8
    (*x8)(...);
    (*x8)(...);
    sub_1AFCA4(...); // call internal at 0xf5344
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf534c
    _ZN14MTFilterKernel17MTDrawArrayFilter11bindTextureEv(...); // call internal at 0xf5354
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv(...); // call internal at 0xf535c
    const char* str = "uMVPMatrix";
    _ZN14MTFilterKernel15GPUImageProgram19SetUniformMatrix4fvEPKcPKfbib(...); // call internal at 0xf53bc
    (*x8)(...);
    const char* str = "textureWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf53e4
    (*x8)(...);
    const char* str = "textureHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xf5410
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTStrokeDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf54a8
    const char* str = "aPosition";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf54bc
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf54e0
    const char* str = "aTextCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf54f4
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xf5508
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf5538
}
