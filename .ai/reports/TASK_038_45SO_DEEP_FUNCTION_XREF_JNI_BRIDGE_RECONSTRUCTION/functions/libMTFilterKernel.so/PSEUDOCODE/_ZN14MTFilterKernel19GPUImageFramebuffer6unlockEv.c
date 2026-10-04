// Function: MTFilterKernel::GPUImageFramebuffer::unlock()
// RVA: 0x1645a4, Size: 140 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _ZN14MTFilterKernel15GPUImageContext17returnFramebufferEPNS_19GPUImageFramebufferE(...); // call internal at 0x1645ec
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x164604
    const char* str = "FilterKernel";
    const char* str = "ERROR: RtEffectSDK: Tried to overrelease a framebuffer, did you forget to call -useNextFrameForImageCapture before using -imageF";
    __android_log_print(...); // call PLT API at 0x16462c
}
