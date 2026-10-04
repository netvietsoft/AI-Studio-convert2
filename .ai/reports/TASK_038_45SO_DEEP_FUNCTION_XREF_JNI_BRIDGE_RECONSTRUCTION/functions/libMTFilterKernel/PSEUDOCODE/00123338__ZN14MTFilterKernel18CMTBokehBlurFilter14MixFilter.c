// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x123338
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilter14MixFilterToFBOEiiiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x123338 | Size: 324 bytes | SHA256: 3f6ea88a92dc27219c05e673861f055f4c66b964abf86af84b460963c2f7de88
// Callers: 1 | Callees: 3 | Imports: 6

// Calls external APIs: glActiveTexture, glBindFramebuffer, glBindTexture, glClear, glDrawArrays, glViewport
// Strings referenced:
//   "bodyMaskTexture"
//   "gradientTexture"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"

void _ZN14MTFilterKernel18CMTBokehBlurFilter14MixFilterToFBOEiiiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x123338 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x12333c */ stp x24, x23, [sp, #0x10];
    /* 0x123340 */ stp x22, x21, [sp, #0x20];
    /* 0x123344 */ stp x20, x19, [sp, #0x30];
    /* 0x123348 */ mov x29, sp;
    /* 0x12334c */ ldr x19, [x0, #0x150];
    /* 0x123350 */ mov w24, w1;
    /* 0x123354 */ mov w0, #0x8d40;
    /* 0x123358 */ mov w1, w4;
    /* 0x12335c */ mov w21, w6;
    /* 0x123360 */ mov w22, w5;
    glBindFramebuffer();
    glViewport();
    glClear();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
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
}
