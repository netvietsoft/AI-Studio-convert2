// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x132f8c
// Recovered Name: sub_132f8c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x132f8c | Size: 576 bytes | SHA256: ad6c0437a1391e488fb5c9a9411be6785cc9c88f1ff820a8e9030ff3a5e84474
// Callers: 0 | Callees: 8 | Imports: 10

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDrawArrays, glGenFramebuffers, glViewport
// Strings referenced:
//   "inputTextureCoordinate"
//   "position"
//   "srcImageTex"
//   "texBlurHeightOffset"
//   "texBlurWidthOffset"

void sub_132f8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 144 instructions
    /* 0x132f8c */ stp x29, x30, [sp, #0x60];
    /* 0x132f90 */ str x23, [sp, #0x70];
    /* 0x132f94 */ stp x22, x21, [sp, #0x80];
    /* 0x132f98 */ stp x20, x19, [sp, #0x90];
    /* 0x132f9c */ add x29, sp, #0x60;
    /* 0x132fa0 */ mrs x23, tpidr_el0;
    /* 0x132fa4 */ fmov s8, s1;
    /* 0x132fa8 */ fmov s9, s0;
    /* 0x132fac */ ldr x8, [x23, #0x28];
    /* 0x132fb0 */ mov x19, x0;
    /* 0x132fb4 */ mov w20, w1;
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj();
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    glGenFramebuffers();
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    glViewport();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    glClearColor();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glDrawArrays();
    glBindFramebuffer();
    return x0;
    _ZdlPv();
    sub_1b0544();
    __stack_chk_fail();
}
