// Function: MTFilterKernel::MTSpliceFilterKernel::renderToLastFrameBuffer(MTFilterKernel::GPUImageRotationMode, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0x110c3c, Size: 444 bytes
int64_t _ZN14MTFilterKernel20MTSpliceFilterKernel23renderToLastFrameBufferENS_20GPUImageRotationModeEPNS_19GPUImageFramebufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0x110cbc
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebufferC2EPNS_15GPUImageContextENS_6CGSizeENS_17GPUTextureOptionsEbjji(...); // call internal at 0x110d08
    glFlush(...); // call PLT API at 0x110d18
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0x110d20
    _ZN14MTFilterKernel12MTFilterBase15copyFramebufferEPNS_15GPUImageContextEPNS_19GPUImageFramebufferES4_(...); // call internal at 0x110d30
    const char* str = "SpliceScreenCapture";
    (*x8)(...);
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x110d74
    const char* str = "FilterKernel";
    const char* str = " _needFreezeLastFrambuffer = %d,_hasFreezeLastFrambuffer = %d,_lastOutputFramebuffer->texture() = %d";
    __android_log_print(...); // call PLT API at 0x110da4
    return a0;
    _ZdlPv(...); // call PLT API at 0x110dd8
    sub_1B0544(...); // call internal at 0x110df0
    __stack_chk_fail(...); // call PLT API at 0x110df4
}
