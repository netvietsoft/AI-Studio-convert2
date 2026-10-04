// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf6c4c
// Recovered Name: sub_f6c4c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf6c4c | Size: 1100 bytes | SHA256: 448d70e1fd882943b1d175852aaa85c056b33c142a2b747df331fc36fbefd77c
// Callers: 0 | Callees: 7 | Imports: 12

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDrawArrays, glEnableVertexAttribArray, glVertexAttribPointer, memmove, strlen
// Strings referenced:
//   "blurImageTexture"
//   "inputImageMaskTexture"
//   "inputImageTexture"
//   "mode"
//   "texHeightOffset"

void sub_f6c4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 275 instructions
    /* 0xf6c4c */ stp x29, x30, [sp, #0x60];
    /* 0xf6c50 */ stp x26, x25, [sp, #0x70];
    /* 0xf6c54 */ stp x24, x23, [sp, #0x80];
    /* 0xf6c58 */ stp x22, x21, [sp, #0x90];
    /* 0xf6c5c */ stp x20, x19, [sp, #0xa0];
    /* 0xf6c60 */ add x29, sp, #0x60;
    /* 0xf6c64 */ mrs x26, tpidr_el0;
    /* 0xf6c68 */ mov x19, x0;
    /* 0xf6c6c */ mov w20, w1;
    /* 0xf6c70 */ ldr x8, [x26, #0x28];
    /* 0xf6c74 */ stur x8, [x29, #-0x18];
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZdlPv();
    _ZdlPv();
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
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
    glDrawArrays();
    glBindFramebuffer();
    return x0;
    sub_c3100();
    sub_c3100();
    sub_1b0544();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
