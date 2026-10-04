// Function: MTFilterKernel::MTlabFilterKernelRender::renderToTexture(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*, float)
// RVA: 0x1a8c34, Size: 548 bytes
int64_t _ZN14MTFilterKernel23MTlabFilterKernelRender15renderToTextureEPNS_19GPUImageFramebufferES2_f(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel23MTlabFilterKernelRender20loadMTFilterToRenderEv(...); // call internal at 0x1a8c64
    _ZN14MTFilterKernel15GPUImageContext21clearRenderBufferPoolEv(...); // call internal at 0x1a8cac
    _ZN14MTFilterKernel15GPUImageContext20clearFramebufferPoolEv(...); // call internal at 0x1a8cb4
    _ZN14MTFilterKernel11RenderState5storeEv(...); // call internal at 0x1a8cd8
    _ZN14MTFilterKernel12GlobalConfig5resetEv(...); // call internal at 0x1a8ce4
    _ZN14MTFilterKernel15GPUImageContext24setFBOTextureFromOutsideEPNS_19GPUImageFramebufferES2_(...); // call internal at 0x1a8cf4
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer13clearAllLocksEv(...); // call internal at 0x1a8da0
    _ZN14MTFilterKernel19GPUImageFramebuffer13clearAllLocksEv(...); // call internal at 0x1a8da8
    _ZN14MTFilterKernel15GPUImageContext26removeFramebufferFromCacheEPNS_19GPUImageFramebufferE(...); // call internal at 0x1a8db4
    _ZN14MTFilterKernel15GPUImageContext26removeFramebufferFromCacheEPNS_19GPUImageFramebufferE(...); // call internal at 0x1a8dc0
    _ZN14MTFilterKernel15GPUImageContext20clearFramebufferPoolEv(...); // call internal at 0x1a8dd8
    _ZN14MTFilterKernel15GPUImageContext21clearRenderBufferPoolEv(...); // call internal at 0x1a8de0
    _ZN14MTFilterKernel11RenderState7restoreEv(...); // call internal at 0x1a8dfc
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1a8e2c
    const char* str = "FilterKernel";
    const char* str = "inputFilter==NULL";
    __android_log_print(...); // call PLT API at 0x1a8e4c
}
