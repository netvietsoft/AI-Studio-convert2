// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf70a0
// Recovered Name: sub_f70a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf70a0 | Size: 948 bytes | SHA256: d052d7c3927b00f0f99eac14b01d911f41c586821183d0da729b70fb0bb00e47
// Callers: 0 | Callees: 10 | Imports: 9

// Calls external APIs: __android_log_print, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDrawArrays, glEnableVertexAttribArray, glVertexAttribPointer
// Strings referenced:
//   "FilterKernel"
//   "MTXTDetailsDrawArrayFilter _inputTextureIDArray.size() < 2 return"
//   "blurImageTexture"
//   "colorA"
//   "colorB"

void sub_f70a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 237 instructions
    /* 0xf70a0 */ stp x29, x30, [sp, #0xc0];
    /* 0xf70a4 */ stp x22, x21, [sp, #0xd0];
    /* 0xf70a8 */ stp x20, x19, [sp, #0xe0];
    /* 0xf70ac */ add x29, sp, #0xc0;
    /* 0xf70b0 */ mrs x22, tpidr_el0;
    /* 0xf70b4 */ ldr x8, [x22, #0x28];
    /* 0xf70b8 */ stur x8, [x29, #-0x18];
    /* 0xf70bc */ ldp x9, x8, [x0, #0x160];
    /* 0xf70c0 */ sub x8, x8, x9;
    /* 0xf70c4 */ cmp x8, #7;
    /* 0xf70c8 */ b.hi #0xf70f8;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji();
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji();
    _ZN14MTFilterKernel26MTXTDetailsDrawArrayFilter4blurEjff();
    _ZN14MTFilterKernel26MTXTDetailsDrawArrayFilter19drawWithBlurAndMaskEj();
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel17MTDrawArrayFilter15setUniformParamEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    glClearColor();
    glEnableVertexAttribArray();
    glVertexAttribPointer();
    glEnableVertexAttribArray();
    glVertexAttribPointer();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    glDrawArrays();
    glBindFramebuffer();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    return x0;
    __stack_chk_fail();
}
