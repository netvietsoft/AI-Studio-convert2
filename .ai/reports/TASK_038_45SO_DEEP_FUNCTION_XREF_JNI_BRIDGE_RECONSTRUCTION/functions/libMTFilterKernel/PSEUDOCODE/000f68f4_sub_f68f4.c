// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf68f4
// Recovered Name: sub_f68f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf68f4 | Size: 848 bytes | SHA256: 3b5b2734d88eb2fe40b6883b692983666b0fa95967ac03212dbebe8480e744ab
// Callers: 0 | Callees: 6 | Imports: 12

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDrawArrays, glEnableVertexAttribArray, glVertexAttribPointer, memmove, strlen
// Strings referenced:
//   "srcImageTex"
//   "texBlurHeightOffset"
//   "texBlurWidthOffset"

void sub_f68f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 212 instructions
    /* 0xf68f4 */ stp x29, x30, [sp, #0x60];
    /* 0xf68f8 */ stp x26, x25, [sp, #0x70];
    /* 0xf68fc */ stp x24, x23, [sp, #0x80];
    /* 0xf6900 */ stp x22, x21, [sp, #0x90];
    /* 0xf6904 */ stp x20, x19, [sp, #0xa0];
    /* 0xf6908 */ add x29, sp, #0x60;
    /* 0xf690c */ mrs x26, tpidr_el0;
    /* 0xf6910 */ fmov s8, s1;
    /* 0xf6914 */ fmov s9, s0;
    /* 0xf6918 */ ldr x8, [x26, #0x28];
    /* 0xf691c */ mov x19, x0;
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZdlPv();
    _ZdlPv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
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
