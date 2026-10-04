// Function: MTFilterKernel::MTStrokeDrawArrayFilter::lineFilterToFBO(MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf553c, Size: 640 bytes
int64_t _ZN14MTFilterKernel23MTStrokeDrawArrayFilter15lineFilterToFBOEPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xf556c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xf5574
    glActiveTexture(...); // call PLT API at 0xf557c
    glBindTexture(...); // call PLT API at 0xf558c
    glUniform1i(...); // call PLT API at 0xf559c
    glActiveTexture(...); // call PLT API at 0xf55a4
    glBindTexture(...); // call PLT API at 0xf55b4
    glUniform1i(...); // call PLT API at 0xf55c4
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv(...); // call internal at 0xf55cc
    const char* str = "isBlend";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb(...); // call internal at 0xf55e4
    (*x8)(...);
    (*x8)(...);
    sub_1AFCA4(...); // call internal at 0xf5630
    const char* str = "uMVPMatrix";
    _ZN14MTFilterKernel15GPUImageProgram19SetUniformMatrix4fvEPKcPKfbib(...); // call internal at 0xf5690
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTStrokeDrawArrayFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf5728
    const char* str = "aPosition";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf573c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xf5760
    const char* str = "aTextCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xf5774
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xf5788
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf57b8
}
