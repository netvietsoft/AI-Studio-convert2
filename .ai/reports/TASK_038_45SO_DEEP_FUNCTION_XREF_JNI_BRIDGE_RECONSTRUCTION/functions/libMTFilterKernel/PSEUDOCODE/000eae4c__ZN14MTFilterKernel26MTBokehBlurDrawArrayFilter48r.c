// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeae4c
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xeae4c | Size: 488 bytes | SHA256: d56ef3264c52cdcd93b601c01b82f343ed0c34d57a343e8087decd90531c344e
// Callers: 0 | Callees: 8 | Imports: 0


void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter48renderToTextureWithVerticesAndTextureCoordinatesEPNS_19GPUImageFramebufferES2_RKNS_18MTImgTextureMangerE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 122 instructions
    /* 0xeae4c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xeae50 */ stp x20, x19, [sp, #0x10];
    /* 0xeae54 */ mov x29, sp;
    /* 0xeae58 */ mov x19, x2;
    /* 0xeae5c */ mov x20, x0;
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter16updateParametersEv();
    /* 0xeae64 */ fmov s0, #-5.00000000;
    /* 0xeae68 */ ldr s1, [x20, #0x234];
    /* 0xeae6c */ adrp x8, #0x8d000;
    /* 0xeae70 */ fadd s0, s1, s0;
    /* 0xeae74 */ ldr d1, [x8, #0xd70];
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter16fetchFrameBufferEv();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter15blurFilterToFBOEiPNS_19GPUImageFramebufferEfff();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter15blurFilterToFBOEiPNS_19GPUImageFramebufferEfff();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18bigMaskFilterToFBOEiPNS_19GPUImageFramebufferEf();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18bigMaskFilterToFBOEiPNS_19GPUImageFramebufferEf();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter15blurFilterToFBOEiPNS_19GPUImageFramebufferEfff();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter15blurFilterToFBOEiPNS_19GPUImageFramebufferEfff();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter20bokehBlurFilterToFBOEiiiPNS_19GPUImageFramebufferE();
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter14mixFilterToFBOEiiiPNS_19GPUImageFramebufferE();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    return x0;
    _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE();
    return x0;
}
