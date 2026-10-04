// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x134d94
// Recovered Name: sub_134d94
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x134d94 | Size: 512 bytes | SHA256: 0e3f0b88b63e18e1fe6ed03b736302bd9bd64eda3b8bab351d67c0115f968a3c
// Callers: 0 | Callees: 6 | Imports: 7

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClear, glDrawArrays, glViewport
// Strings referenced:
//   "gain"
//   "gradientTexture"
//   "hairMaskTexture"
//   "inputImageTexture"
//   "inputTextureCoordinate"

void sub_134d94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 128 instructions
    /* 0x134d94 */ stp x29, x30, [sp, #0x30];
    /* 0x134d98 */ stp x26, x25, [sp, #0x40];
    /* 0x134d9c */ stp x24, x23, [sp, #0x50];
    /* 0x134da0 */ stp x22, x21, [sp, #0x60];
    /* 0x134da4 */ stp x20, x19, [sp, #0x70];
    /* 0x134da8 */ add x29, sp, #0x30;
    /* 0x134dac */ mrs x26, tpidr_el0;
    /* 0x134db0 */ mov x23, x0;
    /* 0x134db4 */ mov w22, w1;
    /* 0x134db8 */ ldr x8, [x26, #0x28];
    /* 0x134dbc */ mov w1, w4;
    glBindFramebuffer();
    glViewport();
    glClear();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff();
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glDrawArrays();
    return x0;
    __stack_chk_fail();
}
