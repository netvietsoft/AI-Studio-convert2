// Function: MTFilterKernel::GLUtils::loadTextureToRGBA(MTFilterKernel::GPUImageContext*, unsigned int, int, int)
// RVA: 0x146144, Size: 332 bytes
int64_t _ZN14MTFilterKernel7GLUtils17loadTextureToRGBAEPNS_15GPUImageContextEjii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call PLT API at 0x146184
    glGetIntegerv(...); // call PLT API at 0x146190
    _Znwm(...); // call PLT API at 0x146198
    _ZN14MTFilterKernel14GPUImageFilterC2Ev(...); // call internal at 0x1461a0
    (*x8)(...);
    _Znwm(...); // call PLT API at 0x1461bc
    _ZN14MTFilterKernel20GPUImageTextureInputC2Ev(...); // call internal at 0x1461c4
    _ZN14MTFilterKernel20GPUImageTextureInput22initWithTextureAndSizeEPNS_15GPUImageContextEjNS_6CGSizeE(...); // call internal at 0x1461dc
    (*x8)(...);
    _ZN14MTFilterKernel20GPUImageTextureInput27processTextureWithFrameTimeEf(...); // call internal at 0x1461fc
    _ZN14MTFilterKernel19GPUImageFramebuffer10byteBufferEv(...); // call internal at 0x146204
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0x146210
    glBindFramebuffer(...); // call PLT API at 0x14621c
    glViewport(...); // call PLT API at 0x146228
    return a0;
    _ZdlPv(...); // call PLT API at 0x146270
    sub_1B0544(...); // call internal at 0x146288
    __stack_chk_fail(...); // call PLT API at 0x14628c
}
